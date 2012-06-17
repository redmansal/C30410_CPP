#include <iostream>
#include <fstream>
using namespace std;
#include "schedule_oop.h"

Job::Job()                                      /* constructer for Job */
{
	id = 0;
	level = 0;
	startTime = 0;
	duration = 0;
}

int Job::jobRead(fstream& str)                  /* job method to read in from stream to job object */
{
	str >> id;
	if (str.fail())
		return -1;
	str >> level;
	if (str.fail())
		return -1;
	str >> duration;
	if (str.fail())
		return -1;
}

const AircraftId Job::jobid() const             /* getter */
{
	return id;
}

const Level Job::jobLevel() const               /* getter */
{
	return level;
}
const Time Job::jobduration() const             /* getter */
{
	return duration;
}

void Job::add_job_to_crew(Job job)              /* add a job to a crew when startime = 0*/
{
	id = job.jobid();
	level = job.jobLevel();
	startTime = job.job_starting_time();
	duration = job.job_duration();
}

void Job::add_job_to_crew(Job job, Time time_for_end_of_previous_job) /* add a job to crew when start time is not 0 */
{
	id = job.jobid();
	level = job.jobLevel();
	startTime = time_for_end_of_previous_job;
	duration = job.job_duration();
}

const Time Job::job_starting_time() const       /* accessor` */
{
	return startTime;
}


const Time Job::job_duration() const            /* accessor */
{
	return duration;
}

void Job::print_job_info() const                /* output info */
{
	text_formating();
	cout<<id;
	text_formating();
	cout<<level;
	text_formating();
	cout<<startTime;
	text_formating();
	cout<<duration;
}


Time Job::job_finish_time() const /* find jobs finish time  */
{
	return startTime + duration;
	//cout<<"startTime: "<<startTime;
}

// ////////////////////////////   //
// Interface for the Schedule ADT //
// ////////////////////////////   //

Schedule::Schedule()                            /* constructor */
{
	noJobs = 0;
}

int Schedule::scheduleNumJobs() const           /* getter */
{
	return noJobs;
}

Time Schedule::scheduleMinStartTime() const     /* find the earliest time a crew can start a job */
{
	Time min_start_time;
	if(noJobs > 0)
	{
		min_start_time = jobList[noJobs - 1].job_finish_time();
	}
	else
	{
		min_start_time = 0;
	}
	return min_start_time;
}

void Schedule::add_job_to_crew_schedule(Job job) /* a particular job to a crews schedule */
{
	if(noJobs == 0)
	{
		noJobs++;
		jobList[noJobs - 1].add_job_to_crew(job);
	}
	else
	{
		noJobs++;
		jobList[noJobs - 1].add_job_to_crew(job, jobList[noJobs -2].job_finish_time());//overloading method 
                                                /* calling the method add_job_to_crew bound to object jobList[noJobs - 1] with the 
						 * parameter job and the previous jobs finish time(this will be used as the next jobs
						 * start time*/
	}
}

void Schedule::print_schedule_info()
{
	print_characters(80,'-');
	text_formating();
	cout<<"Job No.";
	text_formating();
	cout<<"Aircraft Id";
	text_formating();
	cout<<"Level";
	text_formating();
	cout<<"Start-Time";
	text_formating();
	cout<<"Duration"<<endl;
	print_characters(80,'-');
	
	for(int i = 0; i < noJobs; i++)
	{
		text_formating();
		cout<<i;
		jobList[i].print_job_info();
		cout<<endl;
	}
	
}

bool Schedule::schedule_check_crew_schedule_is_valid(Level level )
{
	bool valid = true;
	for(int i = 0; i < noJobs && valid == true; i ++)
	{
		if(jobList[i].jobLevel() > level) /* ensure alocated crew has the correct skill levels */
			valid = false;
		if((jobList[i].job_starting_time() < jobList[i -1 ].job_finish_time()) && (i > 0)) /* this if statment checks to make 
							sures that each crews schedule jobs occurs after each other. this means
							that no crew will be assigned multiple jobs at the same time*/
			valid = false;
	}
	return valid;
}

int Schedule::no_of_jobs() const                /* accessor */
{
	return noJobs;
}
// //////////////////////////// //
// Interface for the Crew ADT   //
// //////////////////////////// //

Crew::Crew()
{
	level = 0;
	cost = 0;
	//cout<<"level"<<level<<endl;
	//cout<<"cost"<<cost<<endl;
}

void Crew::newcrew(fstream& str_crews_list)     /* copy in crew values for the stream str_crews_list */
{
	str_crews_list>>level;
	str_crews_list>>cost;
}

void Crew::add_to_schedule(Job job)
{
	schedule.add_job_to_crew_schedule(job);
}

const Level Crew::crewLevel() const
{
  return level;
}

void Crew::print_crew() const
{
	text_formating();
	cout<<level;
	text_formating();
	cout<<cost<<endl;
}

Crew& Crew::jobFindCrewForJob(Job job, Crew crewlist[], int numCrews) const  
                                                /* this method will select the most suitable crew for a given job 
						 * it will prioritise the cheapest crews above the rest but still assign 
						 * more expensive crews to ensure work gets completed sooner*/
{
	Crew temporary;
	int i;
	Level jlevel;
	Time minTime;
	Time earliest_time_available;
	int found;
	int cindex;
	Cost least_crew_cost;
	jlevel = job.jobLevel();
	found = false;

	if(temporary.crew_jobs_uneven_spread(crewlist, numCrews) == true)
                                                /* the crew who can do the work the earliest will be selected here when the
						 * there is a gap of greater than 40 hours between the earliest available crew and the
						 * crew starting the soonest*/
	{
		for(i=0 ; i < numCrews; i++)
		{
			if (crewlist[i].crewLevel() >= jlevel)
			{
				if(!found || crewlist[i].crew_available_time() < earliest_time_available)
				{
					earliest_time_available = crewlist[i].crew_available_time();
					cindex = i;
					found = true;
				
				}
			}
		}

	}
	else
	{                                       /* this loop will select the cheapest crew for the job */
		for(i=0 ; i < numCrews; i++)
		{
			if (crewlist[i].crewLevel() >= jlevel)
			{
				if(!found || crewlist[i].crew_cost() < least_crew_cost)
				{
					least_crew_cost = crewlist[i].crew_cost();
					cindex = i;
					found = true;
				
				}
			}
		}
	}

	return crewlist[cindex];
	//cost = crewlist[5].crewcost();
}

Schedule& Crew::crewSchedule()
{
	return schedule;
}


void Crew::print_crew_info()
{
	text_formating();
	cout<<level;
	text_formating();
	cout<<cost;
	text_formating();
	cout<<schedule.no_of_jobs()<<endl;
	schedule.print_schedule_info();
	cout<<endl;

}


const Cost Crew::crew_cost() const
{
	return cost;
}

Time Crew::crew_available_time() const
{
	return schedule.scheduleMinStartTime();
}


bool Crew::crew_jobs_uneven_spread(Crew crewlist[], int numcrew) /* method to see if the allocation of work is not
								    evenly spread among the crews.  This is to ensure that all to jobs
								    are not alocated to the three cheapest crews.*/
{
	bool un_even = false;
	Time latest = 0;
	Time earliest = 0;
	for(int i = 0; i < numcrew; i++)
	{
		if (crewlist[i].crew_available_time() > latest)
			latest = crewlist[i].crew_available_time();
		if (crewlist[i].crew_available_time() < earliest)
			earliest = crewlist[i].crew_available_time();
	}
	if (latest > (earliest + 40))
		un_even = true;
	else
		un_even = false;
	return un_even;
}

bool Crew::crew_check_crew_schedule_is_valid()  /* validation method */
{
	bool valid = false;
	valid = schedule.schedule_check_crew_schedule_is_valid(level);
	return valid;
}

// //////////////////////////// //
// Interface for the MaintenanceList ADT   //
// //////////////////////////// //

MaintenanceList::MaintenanceList()              /* constructor for MaintenanceList` */
{
	noJobs = 0;
}

void MaintenanceList::maintenanceListAddJob(Job job) /* add job to the maintenance list */
{
  jobList[noJobs] = job;
  noJobs++;
}

Job& MaintenanceList::maintenanceListJobNumber(int i) /* return a reference to a job in the list */
{
	return jobList[i];
}

void MaintenanceList::maintenanceList_PrintAllJobs() const
{
	cout<<endl<<endl;
	print_characters(80,'-');
	int j = 0;
	cout<<endl<<"MaintenanceList details:"<< endl;
	print_characters(80,'-');
	text_formating();
	cout<<"Plane ID";
	text_formating();
	cout<<"Skill Level";
	text_formating();
	cout<<"Duration"<<endl;
	print_characters(80,'-');

	for(int i = 0; i < noJobs; i++)
	{
		text_formating();
		cout<<jobList[i].jobid();
		text_formating();
		cout<<jobList[i].jobLevel();
		text_formating();
		cout<<jobList[i].jobduration()<<endl;
	}
}

void text_formating()
{
	cout.width(15);
	cout.precision(3);
	cout.setf(ios::showpoint);
	cout.setf(ios::right | ios::adjustfield);
}

void print_characters(int times_to_print, char character)
{
  	for(int j=1; j <= (times_to_print); j++)
	{	
		cout<<character;
	}
}

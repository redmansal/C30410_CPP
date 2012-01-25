/*	ScheduleMain_oop.cpp: This program schedules the the work of a airplane maintenance company 
*  	Authors: Colm Nolan
*  	Last modified: 18/04/11
***/

#include <iostream>
#include <fstream>
using namespace std;
#include "schedule_oop.h"                       /* including header file containing classes and  */

int main()
{
	const int numCrews = 12;                      /* total crews set to 12 */
	int numJobs = 0;                              /* variable numJobs */

	MaintenanceList mlist;                        /* declaring object mlist of ADT MaintenanceList */
	Crew crewlist[numCrews];                      /* declaring an array of objects of type Crew 3 times */
	Job job;                                      /* declaring object job of ADT Job */

	fstream str_crews_list("crews.list", ios::in);

	for(int i = 0; i < numCrews; i++)
	{
		crewlist[i].newcrew(str_crews_list); /* assigning the crews info from the list to each crew memmber object */
	}
	str_crews_list.close();                 /* close the stream to the crews.list file */

	cout<<endl<<endl;
	print_characters(80,'-');
	cout<<endl<<"Crew details:"<< endl;
	print_characters(80,'-');
	text_formating();
	cout<<"Crew No.";
	text_formating();
	cout<<"Level";
	text_formating();
	cout<<"Cost"<<endl;
	print_characters(80,'-');

	for(int j = 0; j < numCrews; j++)       /* printing  the crew details*/
	{
		text_formating();
		cout<<j;
		crewlist[j].print_crew();
	}

	fstream str("jobs.list", ios::in);      /* bringing in jobs.list into str  */
	while (job.jobRead(str) != -1)          /* copying the details from the str into the job object and if the end of file is reached
						   -1 will be returned. When -1 is returned the loop will be exited*/
	{
		numJobs++;
		mlist.maintenanceListAddJob(job);
	}
	str.close();                            /* close str stream */

	mlist.maintenanceList_PrintAllJobs();   /* print the maintenance list of jobs */

	for (int i = 0; i < numJobs; i++)       /* loop through all the jobs on the maintenance list copy to job object 
						   then find which crew is most suitable for the job. Finally the job is assigned to
						   that crews schedule*/
	{
		job = mlist.maintenanceListJobNumber(i); /* copying the job from the maintenance List into the job */
		Crew& most_suitable_crew = most_suitable_crew.jobFindCrewForJob(job,crewlist, numCrews);
		most_suitable_crew.add_to_schedule(job);
	}

	cout<<endl<<endl;
	print_characters(80,'-');
	cout<<endl<<endl<<"Crew Validity"<<endl<<endl;

	bool valid = false;

	for (int i = 0; i <numCrews; i++)
	{
		valid = false;
		valid = crewlist[i].crew_check_crew_schedule_is_valid(); /* this member will check if the crew is valid */
		if (valid == true)
		{
			cout<<"Crew: "<<i<<" is valid"<<endl;
		}
		else 
			cout<<"Crew: "<<i<<" is not valid"<<endl;

	}

	cout<<endl<<endl;

	for (int i = 0; i < numCrews; i++)      /* this loop will output the crews details */
	{
		print_characters(80,'-');
		text_formating();
		cout<<"Crew No.";
		text_formating();
		cout<<"Skill Level";
		text_formating();
		cout<<"Cost";
		text_formating();
		cout<<"Total Jobs"<<endl;
		print_characters(80,'-');
		text_formating();
		cout<<i;
		crewlist[i].print_crew_info();
		cout<<endl<<endl<<endl;
	}
	return 0;
}

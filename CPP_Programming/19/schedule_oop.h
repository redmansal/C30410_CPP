#define true 1
#define false 0

typedef int AircraftId;                         /* ADT for airplane ID */
typedef int Time;                               /* ADT for the time  */
typedef int Level;                              /* ADT for the Level required dor a job or the skill level of a crew */
typedef int Cost;                               /* ADT for how much each crew charges for a job */

const int MaxJobs=100;
const int MaxListSize=100;                      /* these consts will be used to limit the size of the program using static memory */
void text_formating();
void print_characters(int times_to_print, char character); /* for formatting purposes */

class Job 
{
	private:
	AircraftId id;                          /* these are the different fields involved with the Job ADT */
	Level level;
	Time startTime;
	Time duration;

	public:
	Job();                                  /* constructer for job */
	int jobRead(fstream& str);              /* this method will be used to read in data into mlist object */
	const AircraftId jobid() const;         /* accessor method */
	const Level jobLevel() const;           /* accessor method */
	const Time jobduration() const;         /* accessor method */
	void add_job_to_crew(Job job);          /* mutator method */
	void add_job_to_crew(Job job, Time time_for_end_of_previous_job); /* mutator method */
	const Time job_starting_time() const;;  /* accessor method */
	const Time job_duration() const;;       /* accessor method */
	void print_job_info() const;
	Time job_finish_time() const;/* accessor method */
};

class Schedule {                                /* Schedule class */
	private:
	int noJobs;                             /* total jobs in schedule */
	Job jobList[MaxJobs];                   /* array of to type Job called jobList */

	public:
	int no_of_jobs() const;                 /* access the number of jobs */
	Schedule();                             /* schedule constructer */
	Time scheduleMinStartTime() const;      /* funtion to find the minimum start time */
	int scheduleNumJobs() const;
	void add_job_to_crew_schedule(Job job); /* this funtion will add the job to the crew schedule */
	void print_schedule_info();             /* print the schedule info */
	bool schedule_check_crew_schedule_is_valid(const Level level); /* find out if the crews schedule is valid */
};

class Crew 
{
	private:
	Level level;                            /* each crews private field */
	Cost cost;
	Schedule schedule;
	
	public:
	Crew();                                 /* crews default constructor */
	const Level crewLevel() const;          /* accessor method */
	const Cost crew_cost() const;           /* accessor method */
	void print_crew() const;                /* print the crews details */
	Crew& jobFindCrewForJob(Job job, Crew crewlist[], int numCrews) const; /* method to find the most suitable crew for a given job */
	Schedule& crewSchedule();               /* get a reference to a crews schedule */
	void add_to_schedule(Job job);          /* add a job to the crews schedule */
	void print_crew_info();
	Time crew_available_time() const;       /* accessor method */
	void newcrew(fstream& str_crews_list);  /* adding details about crew to the object crew */
	bool crew_jobs_uneven_spread(Crew crewlist[], int numcrew); /* this ensures that jobs will be evenly spread  */
	bool crew_check_crew_schedule_is_valid(); /* validate crew */
};

class MaintenanceList 
{
	private:
	int noJobs;                             /* no of jobs */
	Job jobList[MaxListSize];               /* array of jobs */

	public:
	MaintenanceList();                      /* constructer for maintenance list */
      	void maintenanceListAddJob(Job job);    /* add a job to the main */
	Job& maintenanceListJobNumber(int i);
        void maintenanceList_PrintAllJobs() const;
};

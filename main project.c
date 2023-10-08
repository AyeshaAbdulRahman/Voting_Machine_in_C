#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
struct voterData{
	char name[50];
	int age;
	int vote;
	char party[50];
	char gender;
    int district;
    char cnic[20];
};
int i;
struct VoteCounter{
	int countPmln,countJI,countPPP,countMQM,countPTI;
};
int FrontPage();
void DistrictVoterReg(char FileName[],char cnic[]);
int castVote();
void Admin();
int MainAdmin();
void ViewLiveVotes();
int CnicSearch(char cnic[],char FileName[] );
int District1();
int District2();
int District3();
int District4();
int District5();
int GlobalVote(struct VoteCounter);
int GlobalVote2(struct VoteCounter v,int n);
void DistrictData(char FileName[],int n);
int staticstics();
void GenderStats();
void ageStats();
const char* age(int n1,int n2);
const char* DisWinner( int n1);

int FrontPage(){
	printf("\n\n**************************************************************************\n");
	printf("*****************************************************************************\n");
	printf("------------------------ELECTRONIC VOTING MACHINE----------------------------\n");
	printf("*****************************************************************************\n");
	printf("****************************************************************************\n");
	printf("\n\n____________________REPRESENTED BY_________________________________\n\n");
	printf("\t\t(22k-4591) Ayesha Abdul Rahman\n");
	printf("\t\t(22k-4546) Fiza Farooq\n");
	printf("\n\n\n\n\n\n\n\n\nEnter any key to proceed.");
	getche();
	system("Cls");
	return 0;
}
/////////////////////////////////////////Main //////////////////////////////////////////////////////
int main(){
int i;
int choice;
FrontPage();

do{
	printf("*****************************************************************************\n");
	printf("*****************************************************************************\n");
	printf("\n\n ###### Welcome to Election/Voting 2022 #####");
	printf("*****************************************************************************\n");
	printf("*****************************************************************************\n");
	printf("\n\n 1. Cast the Vote");
	printf("\n\n 2. Login as an Administrator");
	printf("\n\n 3. View live Voting Score.");
	printf("\n\n 0. Exit.");
	printf("\n\n Please enter your choice : ");
	fflush(stdin);	
	scanf("%d", &choice);
    system("cls");

	switch(choice)
	{
		case 1: castVote();break;
		case 2: Admin();break;
		case 3: ViewLiveVotes();break;
		case 0:break;
		default: printf("\n Error: Invalid Choice");break;
	}
	
}
while(choice!=0);

//hold the screen
getchar();

return 0;
}
//////////////////////////////////////////////////Vote Casting///////////////////////////////////////////////////////
int castVote(){
	int District;
	char cnic[15];
	printf("\n*********************************************");
	printf("\n---------------------------------------------"); 	
	printf("\n        Welcome to Vote Casting\n");
	printf("\n*********************************************");
	printf("\n---------------------------------------------\n"); 	
	printf("Enter Your District...( 1 Or 2 Or 3 Or 4 0r 5)\n1.Karachi East\n2.Karachi West\n3.Karachi Central\n4.Karachi South\n5.District Malir\n");
	fflush(stdin);
	scanf("%d",&District);
	switch(District){
		case 1:
			system("cls");

			District1();			   
			break;
		case 2:
			system("cls");
			District2();
	    	break;
	    
	    case 3:
            system("cls");
            District3();
	    	break;
	    case 4:
            system("cls");
			District4();
	    	break;
		case 5:
            system("cls");
            District5();
	    	break;
		default:
		    printf("Error! Invalid Choice..\n");
		    return 0;
			break;
		}
}
//////////////Function for sreaching 0r matching Any Existing CNIC////////////////////////	
int CnicSearch(char cnic[],char FileName[]){
	FILE *fptrCnic;
	fptrCnic=fopen(FileName,"r");
	int bufferLength = 15;
	char buffer[bufferLength]; /* not ISO 90 compatible */
	int result;
	
	while(fgets(buffer, bufferLength+1, fptrCnic)) {
		//printf("*** buffer =  %s\n", buffer);  
		//printf("*** cnic   =  %s\n", cnic); 
	  	result = strcmp(buffer, cnic); 
	  	//printf("*** result = %d\n", result);  
	   	if(result == 0){
	    	break;
	    }
	}	
	fclose(fptrCnic);
	return result;
}
//////////////////////////////Voting Data Entering///////////////////////////////////////////////////////////////

int GlobalVote(struct VoteCounter v) {
	printf("*****\n");
	FILE*fptrCnt;
	
	fptrCnt=fopen("Vote_Count.txt","a+");
	if(fptrCnt==NULL){
       fprintf(stderr, "\nError opening file\n");
	exit(1);
    }
    if(v.countPTI>=1){
    	v.countPTI=1;
	}else if (v.countMQM>=1){
		v.countMQM=1;
	}else if(v.countPmln>=1){
		v.countPmln=1;
	}else if(v.countPPP>=1){
		v.countPPP=1;
	}else if(v.countJI>=1){
		v.countJI=1;
	}
	fwrite(&v, sizeof(struct VoteCounter), 1, fptrCnt);
    if(fwrite != 0)
        printf("Thank you very much for your Vote !\n");
	else
        printf("Error in Vote Casting file !\n");
 
//    fprintf(fptrCnt,"%d %d %d %d %d",v.countPTI++,v.countJI++,v.countMQM++,v.countPmln++,v.countPPP++);
    // close file
    fclose (fptrCnt);
 
    return 0;   
    

	//read globalvotes structure from globalVotes.txt 
	
	// add +1 in paryty passed
	
	// write structure into globalVotes.txt  
	
}
//////////////////////////////////////Case 2 issue//////////////////////////////////////////////////
int GlobalVote2(struct VoteCounter v,int n) {
		v.countPmln=1;
		FILE*fptrCnt;
	
	fptrCnt=fopen("Vote_Count.txt","a+");
	if(fptrCnt==NULL){
       fprintf(stderr, "\nError opening file\n");
	exit(1);
    }
	
	fwrite(&v, sizeof(struct VoteCounter), 1, fptrCnt);
    if(fwrite != 0)
        printf("Thank you very much for your Vote !\n");
	else
        printf("Error in Vote Casting file !\n");
 
//    fprintf(fptrCnt,"%d %d %d %d %d",v.countPTI++,v.countJI++,v.countMQM++,v.countPmln++,v.countPPP++);
    // close file
    fclose (fptrCnt);
 
    return 0;   
    

	//read globalvotes structure from globalVotes.txt 
	
	// add +1 in paryty passed
	
	// write structure into globalVotes.txt  
	
}
///////////////////////////////Data Collection For District 1///////////////////////////////////////////
int District1(){
	struct voterData voter;
	struct VoteCounter v={0,0,0,0,0};
	char cnic[15];	
	char District1DataFile[]="District1Data.txt";	
	char cnicDataFile[] = "CnicData.txt";
	FILE *fptrdis1;
	FILE *fptrCnic;	
	printf("\n*********************************************");
	printf("\n---------------------------------------------"); 
	printf("\n\nWelcome to District Karachi East\n\n");
	printf("\n*********************************************");
	printf("\n---------------------------------------------"); 	
	printf("\nEnter your CNIC (including '-')\n");
	fflush(stdin);
	scanf("%s",cnic);
	if(cnic[5]!='-'|| cnic[13]!='-'){
	printf("\nTry Again! You entered CNIC without (-) or in wrong pattern.\n");
		getche();
    	system("cls");
	return 0;
	}
    int res = CnicSearch(cnic ,cnicDataFile);
	if(res==0){
	    printf("OPPS! you cannot vote\nCNIC : %s already found in voting registration!!!\n\n", cnic);
	    system("cls");
	    getche();
		return 0; 
	}

	int match=CnicSearch(cnic,District1DataFile);
	if(match!=0){
	printf("You are not registered in District : Karchi East\n");
	getche();
	system("cls");
	return 0;
		}
	voter.district=1;
    printf("Enter Name ...\n");
    fflush(stdin);
    gets(voter.name);
    printf("Enter Gender.....\nF for Female & M for Male. \t\n");
    fflush(stdin);
	scanf("%c",&voter.gender);
	if(voter.gender!='F' &&  voter.gender!='f' &&  voter.gender!='m'&& voter.gender!='M'){
		printf("You Entered your wrong Gender.\n");
		getche();
		system("cls");
		return 0;
	}
    printf("Enter Age\n");
    fflush(stdin);
	scanf("%d",&voter.age);
	   if(voter.age<18 || voter.age>150){
	   for(i=0; voter.age<18 || voter.age>150; i++){
		   	printf("Your age is must be greater than 17\nEnter Age again\n");
		   	fflush(stdin);
			scanf("%d",&voter.age);
	   }}
   printf("\n\n***********************************************************\n\n");
   printf("Enter your vote...\n"); 
   printf("\t Press 1,2,3,4,5 \n");
   printf("1.PTI\n");
   printf("2.PMLN\n");
   printf("3.JamateIslami\n");
   printf("4.MQM\n5.PPP\n ");
   printf("\n\n***********************************************************\n\n");
   fflush(stdin);
   scanf("%d",&voter.vote);
   fflush(stdin);
   //printf("\n*** cnicDataFile = %s \n ",cnicDataFile);
   ///////////CASE 2 ISSUE ////
   char cnic_copy[15];
   strcpy(cnic_copy, cnic);
   ///////////CASE 2 ISSUE ////
   //printf("\n*** 8 cnic ***=%s***\n",cnic);
   //printf("\n*** 8 cnic_copy ***=%s***\n",cnic_copy);
  // printf("\n*** after flush \n ");
    switch(voter.vote) {
     case 1:
     	//printf("\n*** case 1 \n ");
        strcpy(voter.party,"PTI");
        v.countPTI=1;
        GlobalVote(v);
     break;
     case 2:
     	//printf("\n*** 9 cnic ***=%s***\n",cnic);
     	//printf("\n*** 9 cnic ***=%s***\n",cnic_copy);
     	printf("\n");
     	int cnicLen01 =  strlen(cnic);     	
        strcpy(voter.party,"PMLN");
		//int n=1;
        v.countPmln=1;
		int cnicLen02 =  strlen(cnic);
		
		///////////CASE 2 ISSUE ////
		if (cnicLen01!=cnicLen02){
			strcpy(cnic,cnic_copy);
			
		}
		///////////CASE 2 ISSUE ////
        int n=2;
        GlobalVote2(v,n);
     break;
     case 3:
        strcpy(voter.party,"JI");
        v.countJI=1;
        GlobalVote(v);
     break;
     case 4:
        strcpy(voter.party,"MQM");
        v.countMQM=1;
        GlobalVote(v);
     break; 
     case 5:
        strcpy(voter.party,"PPP");
        v.countPPP=1;
        GlobalVote(v);
     break;
	 default:
	 	printf("You Entered something wrong..\n");
	 break;
 } 	
    strcpy(voter.cnic,cnic);
	fptrCnic = fopen("CnicData.txt","a+");
	if(fptrCnic == NULL){
	   fprintf(stderr, "\nError opening file\n");
	   //printf("Oh dear, something went wrong with read()! %s\n", strerror(errno));
	exit(1);
	   }
	//printf("\n*** after fopen \n ");
	
	//printf("\n*** cnic ***=%s***\n",cnic);
	//printf("\n*** voter.cnic ***=%s***\n",voter.cnic);
	
	fprintf(fptrCnic,"\n%s",cnic);
	fclose(fptrCnic);	
	FILE *fptrvote;
	if(fptrvote == NULL){
        fprintf(stderr, "\nError opening file\n");
	exit(1);
    }
    
//	fprintf(fptrvote,"%s %c %d %s\n",voter.name,voter.gender,voter.age,voter.party);
//	fclose(fptrvote);
// write struct to file
	
	//printf("** voter district = %d", voter.district);
	
    fwrite(&voter, sizeof(struct voterData), 1, fptrvote);
    fflush( stdout );
	if(fwrite != 0)
        printf("Your Vote is Cast successfully !\n");
    else
        printf("Error in Vote Casting file !\n");
 
    // close file
    fclose (fptrvote);
    printf("Enter Any Key To Proceed\n");
    getche();
    system("cls"); 
    return 0;    
}

///////////////////////////////Data Collection For District 2///////////////////////////////////////////
int District2(){
	struct voterData voter;
    struct VoteCounter v={0,0,0,0,0};
	char cnic[15];	
	char District2DataFile[]="District2Data.txt";	
	char cnicDataFile[] = "CnicData.txt";
	FILE *fptrdis2;
	FILE *fptrCnic;	
	printf("\n*********************************************");
	printf("\n---------------------------------------------"); 
	printf("\n\nWelcome to District Karachi West\n\n");
	printf("\n*********************************************");
	printf("\n---------------------------------------------"); 	
	printf("\nEnter your CNIC (including '-')\n");
	fflush(stdin);
	scanf("%s",cnic);
	if(cnic[5]!='-'|| cnic[13]!='-'){
	printf("\nTry Again! You entered CNIC without (-) or in wrong pattern.\n");
	getche();
	system("cls");
	return 0;
	}
    int res = CnicSearch(cnic ,cnicDataFile);
	if(res==0){
	    printf("OPPS! you cannot vote\nCNIC : %s already found in voting registration!!!\n\n", cnic);
	    system("cls");
	    getche();
		return 0; 
	}

	int match=CnicSearch(cnic,District2DataFile);
	if(match!=0){
	printf("You are not registered in District : Karchi East\n");
	getche();
	system("cls");
	return 0;
		}
	voter.district=2;
    printf("Enter Name ...\n");
    fflush(stdin);
    gets(voter.name);
    printf("Enter Gender.....\nF for Female & M for Male. \t\n");
    fflush(stdin);
	scanf("%c",&voter.gender);
	if(voter.gender!='F' &&  voter.gender!='f' &&  voter.gender!='m'&& voter.gender!='M'){
		printf("You Entered your wrong Gender.\n");
		getche();
		system("cls");
		return 0;
	}
    printf("Enter Age\n");
    fflush(stdin);
	scanf("%d",&voter.age);
	   if(voter.age<18 || voter.age>150){
	   for(i=0; voter.age<18 || voter.age>150; i++){
		   	printf("Your age is must be greater than 17\nEnter Age again\n");
		   	fflush(stdin);
			scanf("%d",&voter.age);
	   }}
   printf("\n\n***********************************************************\n\n");
   printf("Enter your vote...\n"); 
   printf("\t Press 1,2,3,4,5 \n");
   printf("1.PTI\n");
   printf("2.PMLN\n");
   printf("3.JamateIslami\n");
   printf("4.MQM\n5.PPP\n ");
   printf("\n\n***********************************************************\n\n");
   fflush(stdin);
   scanf("%d",&voter.vote);
   fflush(stdin);
   //printf("\n*** cnicDataFile = %s \n ",cnicDataFile);
   ///////////CASE 2 ISSUE ////
   char cnic_copy[15];
   strcpy(cnic_copy, cnic);
   ///////////CASE 2 ISSUE ////
   //for debuging
   //printf("\n*** 8 cnic ***=%s***\n",cnic);
   //printf("\n*** 8 cnic_copy ***=%s***\n",cnic_copy);
   //printf("\n*** after flush \n ");
    switch(voter.vote) {
     case 1:
        strcpy(voter.party,"PTI");
         v.countPTI=1;
        GlobalVote(v);
     break;
     case 2:
     	printf("\n");
     	//printf("\n*** 9 cnic ***=%s***\n",cnic_copy);
     	//printf("\n*** cnic count ***=%d***\n",strlen(cnic));
     	int cnicLen01 =  strlen(cnic);   	
        strcpy(voter.party,"PMLN");
        v.countPmln=1;
		int cnicLen02 =  strlen(cnic);
		
		///////////CASE 2 ISSUE ////
		if (cnicLen01!=cnicLen02){
			strcpy(cnic,cnic_copy);
		}
		///////////CASE 2 ISSUE ////
        int n=2;
        GlobalVote2(v,n);
        //printf("\n*** 11 cnic ***=%s***\n",cnic);
     break;
     case 3:
        strcpy(voter.party,"JI");
        v.countJI=1;
        GlobalVote(v);
     break;
     case 4:
        strcpy(voter.party,"MQM");
        v.countMQM=1;
        GlobalVote(v);
     break; 
     case 5:
        strcpy(voter.party,"PPP");
        v.countPPP=1;
        GlobalVote(v);
     break;
	 default:
	 	printf("You Entered something wrong..\n");
	 	getche();
	 	system("cls");
	 	return 0;
	 break;
 } 	
    strcpy(voter.cnic,cnic);
	//fptrCnic = fopen(cnicDataFile,"a+");
	fptrCnic = fopen("CnicData.txt","a+");
	if(fptrCnic == NULL){
	   fprintf(stderr, "\nError opening file\n");
	   //printf("Oh dear, something went wrong with read()! %s\n", strerror(errno));
	exit(1);
	   }
	//printf("\n*** after fopen \n ");
	
	//printf("\n*** cnic ***=%s***\n",cnic);
	//printf("\n*** voter.cnic ***=%s***\n",voter.cnic);
	
	fprintf(fptrCnic,"\n%s",cnic);
	fclose(fptrCnic);	
    FILE *fptrvote;
    fptrvote=fopen("VoterData.txt","a+");
    if(fptrvote == NULL){
        fprintf(stderr, "\nError opening file\n");
	exit(1);
    }
    
//	fprintf(fptrvote,"%s %c %d %s\n",voter.name,voter.gender,voter.age,voter.party);
//	fclose(fptrvote);
// write struct to file
	
	//printf("** voter district = %d", voter.district);
	
    fwrite(&voter, sizeof(struct voterData), 1, fptrvote);
    fflush( stdout );
	if(fwrite != 0)
        printf("Your Vote is Cast successfully !\n");
    else
        printf("Error in Vote Casting file !\n");
 
    // close file
    fclose (fptrvote);
    fclose (fptrvote);
	printf("Enter Any Key To Proceed\n");
    getche();
    system("cls");  
    return 0;    
}


///////////////////////////////Data Collection For District 3///////////////////////////////////////////
///////////////////////////////Data Collection For District 3///////////////////////////////////////////
int District3(){
	struct voterData voter;
    struct VoteCounter v={0,0,0,0,0};
	char cnic[15];	
	char District3DataFile[]="District3Data.txt";	
	char cnicDataFile[] = "CnicData.txt";
	FILE *fptrdis3;
	FILE *fptrCnic;	
	printf("\n*********************************************");
	printf("\n---------------------------------------------"); 
	printf("\n\nWelcome to Karachi Central\n\n");
	printf("\n*********************************************");
	printf("\n---------------------------------------------"); 	
	printf("\nEnter your CNIC (including '-')\n");
	fflush(stdin);
	scanf("%s",cnic);
	if(cnic[5]!='-'|| cnic[13]!='-'){
	printf("\nTry Again! You entered CNIC without (-) or in wrong pattern.\n");
	getche();
	system("cls");
	return 0;
	}
    int res = CnicSearch(cnic ,cnicDataFile);
	if(res==0){
	    printf("OPPS! you cannot vote\nCNIC : %s already found in voting registration!!!\n\n", cnic);
	    system("cls");
	    getche();
		return 0; 
	}

	int match=CnicSearch(cnic,District3DataFile);
	if(match!=0){
	printf("You are not registered in District : Karchi East\n");
	getche();
	system("cls");
	return 0;
		}
	voter.district=3;
    printf("Enter Name ...\n");
    fflush(stdin);
    gets(voter.name);
    printf("Enter Gender.....\nF for Female & M for Male. \t\n");
    fflush(stdin);
	scanf("%c",&voter.gender);
	if(voter.gender!='F' &&  voter.gender!='f' &&  voter.gender!='m'&& voter.gender!='M'){
		printf("You Entered your wrong Gender.\n");
		getche();
		system("cls");
		return 0;
	}
    printf("Enter Age\n");
    fflush(stdin);
	scanf("%d",&voter.age);
	   if(voter.age<18 || voter.age>150){
	   for(i=0; voter.age<18 || voter.age>150; i++){
		   	printf("Your age is must be greater than 17\nEnter Age again\n");
		   	fflush(stdin);
			scanf("%d",&voter.age);
	   }}
   printf("\n\n***********************************************************\n\n");
   printf("Enter your vote...\n"); 
   printf("\t Press 1,2,3,4,5 \n");
   printf("1.PTI\n");
   printf("2.PMLN\n");
   printf("3.JamateIslami\n");
   printf("4.MQM\n5.PPP\n ");
   printf("\n\n***********************************************************\n\n");
   fflush(stdin);
   scanf("%d",&voter.vote);
   fflush(stdin);
   //printf("\n*** cnicDataFile = %s \n ",cnicDataFile);
   ///////////CASE 2 ISSUE ////
   char cnic_copy[15];
   strcpy(cnic_copy, cnic);
   ///////////CASE 2 ISSUE ////
    switch(voter.vote) {
     case 1:
        strcpy(voter.party,"PTI");
         v.countPTI=1;
        GlobalVote(v);
     break;
     case 2:
     	printf("\n",cnic);
     	//printf("\n*** 9 cnic ***=%s***\n",cnic_copy);
     	//printf("\n*** cnic count ***=%d***\n",strlen(cnic));
     	int cnicLen01 =  strlen(cnic);
     	//printf("\n*** case 2 \n ");     	
        strcpy(voter.party,"PMLN");
        v.countPmln=1;
		int cnicLen02 =  strlen(cnic);
		
		///////////CASE 2 ISSUE ////
		if (cnicLen01!=cnicLen02){
			strcpy(cnic,cnic_copy);
		}
		///////////CASE 2 ISSUE ////
        int n=2;
        GlobalVote2(v,n);
     break;
     case 3:
     	//printf("\n*** case 3 \n ");
        strcpy(voter.party,"JI");
        v.countJI=1;
        GlobalVote(v);
     break;
     case 4:
     	//printf("\n*** case 4 \n ");
        strcpy(voter.party,"MQM");
        v.countMQM=1;
        GlobalVote(v);
     break; 
     case 5:
     	//printf("\n*** case 5 \n ");
        strcpy(voter.party,"PPP");
        v.countPPP=1;
        GlobalVote(v);
     break;
	 default:
	 	//printf("\n*** case default \n ");
	 	printf("You Entered something wrong..\n");
	 	system("cls");
	 	getche();
	 	return 0;
 } 	
    strcpy(voter.cnic,cnic);
	//fptrCnic = fopen(cnicDataFile,"a+");
	fptrCnic = fopen("CnicData.txt","a+");
	if(fptrCnic == NULL){
	   fprintf(stderr, "\nError opening file\n");
	   //printf("Oh dear, something went wrong with read()! %s\n", strerror(errno));
	exit(1);
	   }
	//printf("\n*** after fopen \n ");
	
	//printf("\n*** cnic ***=%s***\n",cnic);
	//printf("\n*** voter.cnic ***=%s***\n",voter.cnic);
	
	fprintf(fptrCnic,"\n%s",cnic);
	fclose(fptrCnic);	
    FILE *fptrvote;
    fptrvote=fopen("VoterData.txt","a+");
    if(fptrvote == NULL){
        fprintf(stderr, "\nError opening file\n");
	exit(1);
    }
    
//	fprintf(fptrvote,"%s %c %d %s\n",voter.name,voter.gender,voter.age,voter.party);
//	fclose(fptrvote);
// write struct to file
	
	//printf("** voter district = %d", voter.district);
	
    fwrite(&voter, sizeof(struct voterData), 1, fptrvote);
    fflush( stdout );
	if(fwrite != 0)
        printf("Your Vote is Cast successfully !\n");
    else
        printf("Error in Vote Casting file !\n");
 
    // close file     
    fclose (fptrvote);
	printf("Enter Any Key To Proceed\n");
    getche();
    system("cls");  
    
    return 0;    
}

///////////////////////////////Data Collection For District 4///////////////////////////////////////////
int District4(){
	struct voterData voter;
    struct VoteCounter v={0,0,0,0,0};
	char cnic[15];	
	char District4DataFile[]="District4Data.txt";	
	char cnicDataFile[] = "CnicData.txt";
	FILE *fptrdis4;
	FILE *fptrCnic;	
	printf("\n*********************************************");
	printf("\n---------------------------------------------"); 
	printf("\n\nWelcome to Karachi South\n\n");
	printf("\n*********************************************");
	printf("\n---------------------------------------------"); 	
	printf("\nEnter your CNIC (including '-')\n");
	fflush(stdin);
	scanf("%s",cnic);
	if(cnic[5]!='-'|| cnic[13]!='-'){
	printf("\nTry Again! You entered CNIC without (-) or in wrong pattern.\n");
	getche();
	system("cls");
	return 0;
	}
    int res = CnicSearch(cnic ,cnicDataFile);
	if(res==0){
	    printf("OPPS! you cannot vote\nCNIC : %s already found in voting registration!!!\n\n", cnic);
	    system("cls");
	    getche();
		return 0;
	}

	int match=CnicSearch(cnic,District4DataFile);
	if(match!=0){
	printf("You are not registered in District : Karchi East\n");
	system("cls");
	getche();
	return 0;
		}
	voter.district=4;
    printf("Enter Name ...\n");
    fflush(stdin);
    gets(voter.name);
    printf("Enter Gender.....\nF for Female & M for Male. \t\n");
    fflush(stdin);
	scanf("%c",&voter.gender);
	if(voter.gender!='F' &&  voter.gender!='f' &&  voter.gender!='m'&& voter.gender!='M'){
		printf("You Entered your wrong Gender.\n");
		getche();
		system("cls");
		return 0;
	}
    printf("Enter Age\n");
    fflush(stdin);
	scanf("%d",&voter.age);
	   if(voter.age<18 || voter.age>150){
	   for(i=0; voter.age<18 || voter.age>150; i++){
		   	printf("Your age is must be greater than 17\nEnter Age again\n");
		   	fflush(stdin);
			scanf("%d",&voter.age);
	   }}
   printf("\n\n***********************************************************\n\n");
   printf("Enter your vote...\n"); 
   printf("\t Press 1,2,3,4,5 \n");
   printf("1.PTI\n");
   printf("2.PMLN\n");
   printf("3.JamateIslami\n");
   printf("4.MQM\n5.PPP\n ");
   printf("\n\n***********************************************************\n\n");
   fflush(stdin);
   scanf("%d",&voter.vote);
   fflush(stdin);
   //printf("\n*** cnicDataFile = %s \n ",cnicDataFile);
   ///////////CASE 2 ISSUE ////
   char cnic_copy[15];
   strcpy(cnic_copy, cnic);
   ///////////CASE 2 ISSUE ////
   //printf("\n*** 8 cnic ***=%s***\n",cnic);
   //printf("\n*** 8 cnic_copy ***=%s***\n",cnic_copy);
   //printf("\n*** after flush \n ");
    switch(voter.vote) {
     case 1:
        //printf("\n*** case 1 \n ");
        strcpy(voter.party,"PTI");
        v.countPTI=1;
        GlobalVote(v);
     break;
     case 2:
     	printf("\n");
     	//printf("\n*** 9 cnic ***=%s***\n",cnic_copy);
     	//printf("\n*** cnic count ***=%d***\n",strlen(cnic));
     	int cnicLen01 =  strlen(cnic);     	
        strcpy(voter.party,"PMLN");
        v.countPmln=1;
		int cnicLen02 =  strlen(cnic);
		
		///////////CASE 2 ISSUE ////
		if (cnicLen01!=cnicLen02){
			strcpy(cnic,cnic_copy);
		}
		///////////CASE 2 ISSUE ////
        int n=2;
        GlobalVote2(v,n);
        //printf("\n*** 11 cnic ***=%s***\n",cnic);
     break;
     case 3:
        strcpy(voter.party,"JI");
        v.countJI=1;
        GlobalVote(v);
     break;
     case 4:
        strcpy(voter.party,"MQM");
        v.countMQM=1;
        GlobalVote(v);
     break; 
     case 5:
        strcpy(voter.party,"PPP");
        v.countPPP=1;
        GlobalVote(v);
     break;
	 default:
	 	printf("You Entered something wrong..\n");
	 	system("cls");
	 	return 0;
	 break;
 } 	
    strcpy(voter.cnic,cnic);
	//fptrCnic = fopen(cnicDataFile,"a+");
	fptrCnic = fopen("CnicData.txt","a+");
	if(fptrCnic == NULL){
	   fprintf(stderr, "\nError opening file\n");
	   //printf("Oh dear, something went wrong with read()! %s\n", strerror(errno));
	exit(1);
	   }
	//printf("\n*** after fopen \n ");
	
	//printf("\n*** cnic ***=%s***\n",cnic);
	//printf("\n*** voter.cnic ***=%s***\n",voter.cnic);
	
	fprintf(fptrCnic,"\n%s",cnic);
	fclose(fptrCnic);	
    FILE *fptrvote;
    fptrvote=fopen("VoterData.txt","a+");
    if(fptrvote == NULL){
        fprintf(stderr, "\nError opening file\n");
	exit(1);
    }
    
//	fprintf(fptrvote,"%s %c %d %s\n",voter.name,voter.gender,voter.age,voter.party);
//	fclose(fptrvote);
// write struct to file
	
	//printf("** voter district = %d", voter.district);
	
    fwrite(&voter, sizeof(struct voterData), 1, fptrvote);
    fflush( stdout );
	if(fwrite != 0)
        printf("Your Vote is Cast successfully !\n");
    else
        printf("Error in Vote Casting file !\n");
 
    // close file
    fclose (fptrvote);
	printf("Enter Any Key To Proceed\n");
    getche();
    system("cls");  
    return 0;    
}

///////////////////////////////Data Collection For District 5///////////////////////////////////////////
int District5(){
	struct voterData voter;
    struct VoteCounter v={0,0,0,0,0};
	char cnic[15];	
	char District5DataFile[]="District5Data.txt";	
	char cnicDataFile[] = "CnicData.txt";
	FILE *fptrdis5;
	FILE *fptrCnic;	
	printf("\n*********************************************");
	printf("\n---------------------------------------------"); 
	printf("\n\nWelcome to District Malir\n\n");
	printf("\n*********************************************");
	printf("\n---------------------------------------------"); 	
	printf("\nEnter your CNIC (including '-')\n");
	fflush(stdin);
	scanf("%s",cnic);
	
	if(cnic[5]!='-'|| cnic[13]!='-'){
	printf("\nTry Again! You entered CNIC without (-) or in wrong pattern.\n");
	getche();
	system("cls");
	return 0;
	}
    int res = CnicSearch(cnic ,cnicDataFile);
	if(res==0){
	    printf("OPPS! you cannot vote\nCNIC : %s already found in voting registration!!!\n\n", cnic);
	    return 0;
	    system("cls");
	    getche(); 
	}

	int match=CnicSearch(cnic,District5DataFile);
	if(match!=0){
		printf("You are not registered in District : Malir\n");
		getche();
		system("cls");
		return 0;
	}
	
	voter.district=5;
	printf("Enter Name ...\n");
	fflush(stdin);
	gets(voter.name);
	printf("Enter Gender.....\nF for Female & M for Male. \t\n");
    fflush(stdin);
	scanf("%c",&voter.gender);
	if(voter.gender!='F' &&  voter.gender!='f' &&  voter.gender!='m'&& voter.gender!='M'){
		printf("You Entered your wrong Gender.\n");
		getche();
		system("cls");
		return 0;
	}
	printf("Enter Age\n");
	fflush(stdin);
	scanf("%d",&voter.age);
	
	if(voter.age<18 || voter.age>150){
	   for(i=0; voter.age<18 || voter.age>150; i++){
		   	printf("Your age is must be greater than 17\nEnter Age again\n");
		   	fflush(stdin);
			scanf("%d",&voter.age);
	   }}
	   
   printf("\n\n***********************************************************\n\n");
   printf("Enter your vote...\n"); 
   printf("\t Press 1,2,3,4,5 \n");
   printf("1.PTI\n");
   printf("2.PMLN\n");
   printf("3.JamateIslami\n");
   printf("4.MQM\n5.PPP\n ");
   printf("\n\n***********************************************************\n\n");
   fflush(stdin);
   
   scanf("%d",&voter.vote);
   fflush(stdin);
   //printf("\n*** cnicDataFile = %s \n ",cnicDataFile);
   ///////////CASE 2 ISSUE ////
   char cnic_copy[15];
   strcpy(cnic_copy, cnic);
   ///////////CASE 2 ISSUE ////
   //printf("\n*** 8 cnic ***=%s***\n",cnic);
   //printf("\n*** 8 cnic_copy ***=%s***\n",cnic_copy);
   //printf("\n*** after flush \n ");
    switch(voter.vote) {
     case 1:
        strcpy(voter.party,"PTI");
         v.countPTI=1;
        GlobalVote(v);
     break;
     case 2:
     	printf("\n");
     	//printf("\n*** 9 cnic ***=%s***\n",cnic_copy);
     	//printf("\n*** cnic count ***=%d***\n",strlen(cnic));
     	int cnicLen01 =  strlen(cnic);  	
        strcpy(voter.party,"PMLN");
        v.countPmln=1;
		int cnicLen02 =  strlen(cnic);
		
		///////////CASE 2 ISSUE ////
		if (cnicLen01!=cnicLen02){
			strcpy(cnic,cnic_copy);
		}
		///////////CASE 2 ISSUE ////
        int n=2;
        GlobalVote2(v,n);
        //printf("\n*** 11 cnic ***=%s***\n",cnic);
     break;
     case 3:
        strcpy(voter.party,"JI");
        v.countJI=1;
        GlobalVote(v);
     break;
     case 4:
        strcpy(voter.party,"MQM");
        v.countMQM=1;
        GlobalVote(v);
     break; 
     case 5:
        strcpy(voter.party,"PPP");
        v.countPPP=1;
        GlobalVote(v);
     break;
	 default:
	 	printf("You Entered something wrong..\n");
	 	getche();
	 	system("cls");
	 	return 0;
	 break;
 } 	
    strcpy(voter.cnic,cnic);
	//fptrCnic = fopen(cnicDataFile,"a+");
	fptrCnic = fopen("CnicData.txt","a+");
	if(fptrCnic == NULL){
	   fprintf(stderr, "\nError opening file\n");
	   //printf("Oh dear, something went wrong with read()! %s\n", strerror(errno));
	exit(1);
	   }
	//printf("\n*** after fopen \n ");
	
	//printf("\n*** cnic ***=%s***\n",cnic);
	//printf("\n*** voter.cnic ***=%s***\n",voter.cnic);
	
	fprintf(fptrCnic,"\n%s",cnic);
	fclose(fptrCnic);	
    FILE *fptrvote;
    fptrvote=fopen("VoterData.txt","a+");
    if(fptrvote == NULL){
        fprintf(stderr, "\nError opening file\n");
	exit(1);
    }
    
//	fprintf(fptrvote,"%s %c %d %s\n",voter.name,voter.gender,voter.age,voter.party);
//	fclose(fptrvote);
// write struct to file
	
	//printf("** voter district = %d", voter.district);
	
    fwrite(&voter, sizeof(struct voterData), 1, fptrvote);
    fflush( stdout );
	if(fwrite != 0)
        printf("Your Vote is Cast successfully !\n");
    else
        printf("Error in Vote Casting file !\n");
 
    // close file
    fclose (fptrvote);
	printf("Enter Any Key To Proceed\n");
    getche();
    system("cls"); 
 
    return 0;    
}

void Admin(){
	char pwd[20]={"fast@pk#"};//pwd = password
	char entered_pwd[20];
	int i;
	char cnic[15];
	printf("\n***********************************************************************************************");
    printf("\n----------------------------------------------------------------------------------------------\n"); 
	printf("\n\nInstruction:\nYou cannot enter Passward more than 4 times otherwise Administration will be blocked\n");
	printf("\n************************************************************************************************");
    printf("\n----------------------------------------------------------------------------------------------\n"); 
	printf("Enter the password: ");
	scanf("%s",entered_pwd);
	if(strcmp(pwd,entered_pwd)==0){
	    system("cls");
		MainAdmin();
		
	}
	else {
		for(i=3 ; (strcmp(pwd,entered_pwd)==-1 || strcmp(pwd,entered_pwd)==1)  && i>0 ; i--){
			printf("Please enter the correct password you have %d choices : ",i);
			scanf("%s",entered_pwd);}
		if(strcmp(entered_pwd,pwd)==0){
			MainAdmin();	
			}
	    else {
		    printf("\nYou entered so many wrong passwords. This account is locked now.");
		}
	}
}
int MainAdmin(){
   	int administratorchoice,district_choice,n,dis;
	char cnic[16];
   	char FileName[]="VoterData.txt";
   	char FileNameDis1[]="District1Data.txt";
   	char FileNameDis2[]="District2Data.txt";
   	char FileNameDis3[]="District3Data.txt";
   	char FileNameDis4[]="District4Data.txt";
   	char FileNameDis5[]="District5Data.txt";
   	int n1,c;
   	while(1){
   		printf("\n*******************************************\n");
    	printf("\n--------WELCOME TO ADMINISTRATION----------\n");
    	printf("\n*******************************************\n");
		printf("1. Leading Candidatde or Party\n");
		printf("2. Voter's log.\n");
		printf("3. Voter's Registration\n");
		printf("4. Statistics\n");
		printf("5. Winner Party in each District.\n");
		printf("6. Exit\n");
		printf("Kindly, Enter your choice: ");
		scanf("%d",&administratorchoice);
        system("cls"); 
		switch(administratorchoice){
			case 1:
				ViewLiveVotes();
				break;
			case 2:
				printf("\n*********************************************");
	            printf("\n---------------------------------------------\n"); 
				printf("For which district do you want to see voters datails\n");
				printf("*********************************************\n");
	            printf("\n---------------------------------------------\n"); 
				printf("1. East Karachi.\n");
				printf("2. West Karchi.\n");
				printf("3. Central Karachi.\n");
				printf("4. South Karachi.\n");
				printf("5. Malir Karachi.\n");
				scanf("%d",&district_choice);
				switch(district_choice){
					case 1:
					    n=1;
						DistrictData(FileName,n);
						printf("Enter Any Key To Proceed\n");
						getche();
						system("cls");
						break;
					case 2:
						n=2;
						DistrictData(FileName,n);
						printf("Enter Any Key To Proceed\n");
						getche();
						system("cls");					
						break;
					case 3:
					    n=3;
						DistrictData(FileName,n);
						printf("Enter Any Key To Proceed\n");
						getche();
						system("cls");						
						break;
					case 4:
						 n=4;
					    DistrictData(FileName,n);
						printf("Enter Any Key To Proceed\n");
						getche();
						system("cls");						
						break;
					case 5:
					    n=5;
					    DistrictData(FileName,n);
						printf("Enter Any Key To Proceed\n");
						getche();
						system("cls");						
						break;
				}
				break;
			case 3:
				printf( "Welcome To Voters Registration\n");
				printf("Enter voter CNIC (includnig -)\n");
				fflush(stdin);
				gets(cnic);
				if(cnic[5]!='-'|| cnic[13]!='-'){
				printf("\nTry Again! You entered CNIC without (-) or in wrong pattern.\n");
				getche();
				system("cls");
				}
				else if(strlen(cnic)!=15){
					printf("You entered in wrong pattern.\n");
					getche();
					system("cls");
				}
			    else{
			    printf("\n****For which district****\n");
			    printf("1. East Karachi.\n");
				printf("2. West Karchi.\n");
				printf("3. Central Karachi.\n");
				printf("4. South Karachi.\n");
				printf("5. Malir Karachi.\n");
				printf("Enter District\n");
				scanf("%d",&dis);
				fflush(stdin);
				switch(dis){
					case 1:
						DistrictVoterReg(FileNameDis1,cnic);
						printf("Now, voter has Registered in Karachi East.\n");
						getche();
						system("cls");
						break;
					case 2:
						DistrictVoterReg(FileNameDis2,cnic);					    	
						printf("Now, voter has Registered in Karachi West.\n");
						getche();
						system("cls");
						break;
					case 3:
						DistrictVoterReg(FileNameDis3,cnic);
						printf("Now, voter has Registered in Karachi Central.\n");
						getche();
						system("cls");
						break;
					case 4:
						printf("Now, Voter has Registered in Karachi South.\n");
						DistrictVoterReg(FileNameDis4,cnic);
						getche();
						system("cls");
						break;
					case 5:
						printf("Now, Voter has Registered in Karachi \n");
						DistrictVoterReg(FileNameDis4,cnic);
						getche();
						system("cls");
						break;
					default:
					printf("Invalid Choice\n");
					break; 					  						
				}}
				break;
			case 4:
				staticstics();
				break;
			case 5:
				printf("\n*********************************************");
	            printf("\n---------------------------------------------\n"); 
				printf("For which district do you want to see  Winner's details\n");
				printf("*********************************************\n");
	            printf("\n---------------------------------------------\n"); 
				printf("1. District 1\n");
				printf("2. District 2\n");
				printf("3. District 3\n");
				printf("4. District 4\n");
				printf("5. District 5\n");
				scanf("%d",&c);
				switch(c){
					case 1:
						n1=1;
						printf("\n\nIN DISTRICT 1 \nMajority give votes to %s party\n\n",DisWinner(n1));
						printf("Enter Any Key To Proceed\n");
		                getche();
		                system("cls"); 
				        break;
				    case 2:
						n1=2;
				        printf("\n\nIN DISTRICT 2 \nMajority give votes to %s party\n\n",DisWinner(n1));
				        printf("Enter Any Key To Proceed\n");
		                getche();
		                system("cls"); 
						break; 
		    		case 3:
						n1=3;
				        printf("\n\nIN DISTRICT 3 \nMajority give votes to %s party\n\n",DisWinner(n1));
				        printf("Enter Any Key To Proceed\n");
		                getche();
		                system("cls"); 
						break;
		    		case 4:
						n1=4;
				        printf("\n\nIN DISTRICT 4 \nMajority give votes to %s party\n\n",DisWinner(n1));
				        printf("Enter Any Key To Proceed\n");
		                getche();
		                system("cls"); 
						break;
					case 5:
						n1=5;
				        printf("\n\nIN DISTRICT 5 \n\nMajority give votes to %s party\n\n",DisWinner(n1));
				        printf("Enter Any Key To Proceed\n");
		                getche();
		                system("cls"); 
						break;
					default:
						printf("You Entered something\n");
						printf("Enter any key to proceed.\n");
						getche();
						system("cls");
					break ;	
					}   
		        break;
			case 6:
				return 0;
				break;
			default:
				printf("\nInvalid Choice..\n");
				break;
	   }
	}
}
/////////////////////////////////////////////Function to show Winner Party in each district///////////////////
const char* DisWinner(n1){
	 int c1=0;
	 int c2=0;
	 int c3=0;
	 int c4=0;
	 int c5=0;
	 struct voterData voter;
	FILE *fptr;
	fptr=fopen("VoterData.txt","r");
    if(fptr == NULL){
        fprintf(stderr, "\nError opening file\n");
	   exit(1);
    }
	while(fread(&voter, sizeof(struct voterData), 1, fptr)){
        if(voter.district==n1){
    		if(strcmp(voter.party, "PTI") == 0){
		     	c1++;
			}
			if(strcmp(voter.party, "PMLN") == 0){
		        c2++;
			}
			if(strcmp(voter.party, "PPP") == 0){
		        c3++;
			}
			if(strcmp(voter.party, "MQM") == 0){
				c4++;
			}
			
			else {
    			c5++;
			}
	    }	
	}
  printf("Total PTI Votes=%d\n",c1);
  printf("Total PMLN Votes=%d\n",c2);
  printf("Total PPP Votes=%d\n",c3);
  printf("Total MQM Votes=%d\n",c4);
  printf("Total JI Votes=%d\n",c5);
  
	fclose(fptr);		
	if(c1>c2 && c1>c3 && c1>c4 && c1>c5){
		char *party="PTI";	
		return party;
	}
	else if(c2>c1 && c2>c3 && c2>c4 && c2>c5){	
		char *party="PMLN";	
		return party;
		}
	else if(c3>c1 && c3>c2 && c3>c4 && c3>c5){	
		char *party="PPP";	
		return party;
		}
	else if(c4>c1 && c4>c2 && c4>c3 && c4>c5){
		char *party="MQM";	
		return party;	
		}
	else if(c5>c1 && c5>c2 && c5>c3 && c5>c4){
		char *party="JI";	
		return party;
		}
	else {
		char *party="Undecideable";	
		return party;
	}fclose(fptr);
}
	
	
	
///////////////////////////////////////Function To show Staticsitcs///////////////////////////////////////////
int staticstics(){
	while(1){
		int choice;
	    printf("\nWelcome To staticistics\n");
	    printf("\nHow do you want to filterout\n");
		printf("1. Age wise \n");
		printf("2. Gender wise \n");
		printf("3. Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		switch(choice){
		case 1:
			ageStats();
		break;
		case 2:
			GenderStats();
		break;
		case 3:
			system("cls");
			return 0;
		default:
			printf("You Entered some thing wrong\n\n");
			printf("Enter any key to proceed.\n");
	        getche();
			system("cls");
		return 0;
		break;
		}
	}
}
void GenderStats(){
	struct voterData voter;
	int female_voter=0,male_voter=0;
	int counter=0;
	float female_per,male_per;
	FILE *fptr;
	fptr=fopen("VoterData.txt","r+");
    if(fptr == NULL){
        fprintf(stderr, "\nError opening file\n");
	   exit(1);
    }
    while(fread(&voter, sizeof(struct voterData), 1, fptr)){
		if( voter.gender=='m' || voter.gender=='M' ){
			male_voter++;
			counter++;
		}
		if( voter.gender=='f' || voter.gender=='F' ){
			female_voter++;
			counter++;
		}
	}
	female_per=(female_voter*100)/counter;
	male_per=(male_voter*100)/counter;
	printf("******************************************\n");
	printf("There have been %d votes cast.\n",counter);
	printf("******************************************\n");
//	printf("Female   %d\n",female_voter);
//	printf("Male     %d\n",male_voter);
	printf("Female voters constitute %.2f %% of the electorate.\n",female_per);
	printf("Male voters constitute %.2f %% of the electorate.\n\n",male_per);
	fclose(fptr);
	printf("Enter any key to proceed.\n");
	getche();
	system("cls");
}

void ageStats(){
	int choice;
	char ch[22];
    	printf("For which groups:\n");
    	printf("1. For 18-25.\n");
    	printf("2. For 26-40.\n");
    	printf("3. For above 40.\n");
    	printf("Enter your choice: ");
    	scanf("%d",&choice);
    	switch(choice){
    	case 1:
			printf("\n****************************************\n");
			printf("Age group above 18-25\nMajority give votes to %s party.\n\n",age(18,25));
			printf("Enter any key to proceed.\n");
			getche();
			system("cls");
			break;	
    	case 2:
    		printf("\n****************************************\n");
    		printf("From Age group 26 - 40\nMajority give votes to %s party.\n\n",age(26,40));
    		printf("Enter any key to proceed.\n");
	        getche();
			system("cls");
			break;
    	case 3:
    		printf("\n****************************************\n");
    		printf("Age group above 40\nMajority give votes to %s party.\n\n",age(41,150));
    		printf("Enter any key to proceed.\n");
	        getche();
			system("cls");
    		break;
    	default:
			printf("You enter something wrong.\n\n");
			printf("Enter any key to proceed.\n");
	        getche();
			system("cls");
			break;	
    }
    
}
const char* age (int n1,int n2){
     int c1=0;
	 int c2=0;
	 int c3=0;
	 int c4=0;
	 int c5=0;
	struct voterData voter;
	FILE *fptr;
			fptr=fopen("VoterData.txt","r+");
		    if(fptr == NULL){
		        fprintf(stderr, "\nError opening file\n");
			   exit(1);
		    }
	while(fread(&voter, sizeof(struct voterData), 1, fptr)){
        if(voter.age>=n1 && voter.age<=n2){
    		if(strcmp(voter.party, "PTI") == 0){
		     	c1++;
			}
			if(strcmp(voter.party, "PMLN") == 0){
		        c2++;
					}
			if(strcmp(voter.party, "PPP") == 0){
		        c3++;
			}
			if(strcmp(voter.party, "MQM") == 0){
				c4++;
			}
			
			else {
    			c5++;
			}
	    }	
	}
  printf("Total PTI Votes=%d\n",c1);
  printf("Total PMLN Votes=%d\n",c2);
  printf("Total PPP Votes=%d\n",c3);
  printf("Total MQM Votes=%d\n",c4);
  printf("Total JI Votes=%d\n",c5);
  
	fclose(fptr);		
	if(c1>c2 && c1>c3 && c1>c4 && c1>c5){
		char *party="PTI";	
		return party;
	}
	else if(c2>c1 && c2>c3 && c2>c4 && c2>c5){	
		char *party="PMLN";	
		return party;
		}
	else if(c3>c1 && c3>c2 && c3>c4 && c3>c5){	
		char *party="PPP";	
		return party;
		}
	else if(c4>c1 && c4>c2 && c4>c3 && c4>c5){
		char *party="MQM";	
		return party;	
		}
	else if(c5>c1 && c5>c2 && c5>c3 && c5>c4){
		char *party="JI";	
		return party;
		}
	else {
		char *party="Undecideable";	
		return party;
	}
	fclose(fptr);
}




//////////////////////////////////Function To see Candidate details of each District////////////////////////////////////
void DistrictData(char FileName[],int n){
	struct voterData *voterptr , voter;
	voterptr = &voter;
	FILE *fptr;
	fptr=fopen(FileName,"r");
    if(fptr == NULL){
        fprintf(stderr, "\nError opening file\n");
	   exit(1);
    }
    while(fread(&(*voterptr), sizeof(struct voterData), 1, fptr)){
	
//	printf("\n*** voter.district== %d\n", voter.district);
//	printf("\n*** n == %d\n", n);
	
    	if(voterptr->district==n){
			printf("\n---------------------------------------------------------------------------------------\nName %s\tCnic=%s\nGender=%c\tAge=%d\tVote=%s\n",voterptr->name,voterptr->cnic,voterptr->gender,voterptr->age,voterptr->party);
		
		}	
    }
	fclose(fptr);
}

//////////////////////Function to  register Cnic in District//////////////////////////////////////////////////////
void DistrictVoterReg(char FileName[],char cnic[]){
	printf("*********\n");
	int r=CnicSearch(cnic,FileName);
	if(r==0){
		printf("Error!Voter is already registered.\nYou cannot register again.\n\n");
	}
	else{
		FILE *fptrReg;
	    fptrReg=fopen(FileName,"a");
    if(fptrReg == NULL){
        fprintf(stderr, "\nError opening file\n");
	    exit(1);
    }
    fprintf(fptrReg,"\n%s",cnic);
    
	fclose(fptrReg);
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void ViewLiveVotes(void){
	system("cls");
	printf("\n************************************************\n");	
	printf("##---------Welcome To Live Voting Score---------##\n");
	printf("\n***********************************************\n");
	int countPTI=0,countPmln=0,countJI=0,countPPP=0,countMQM=0;
	int total=0;
	struct VoteCounter v;
	FILE *fptrCnt;
	fptrCnt=fopen("Vote_Count.txt","r");
	if(fptrCnt==NULL){
		fprintf(stderr,"\nError Opening file\n");
	    exit(1);
	} 
	while(fread(&v,sizeof(struct VoteCounter),1,fptrCnt)){
		if(v.countPTI==1){
			total++;
		   countPTI++;
		}
		if(v.countJI==1){
		   total++;
		   countJI++;
		}
		if(v.countMQM==1){
		   total++;
		   countMQM++;
		}
		if(v.countPmln==1){
			total++;
			countPmln++;
		}
		if(v.countPPP==1){
			total++;
			countPPP++;
		}
	}
	printf("Total votes casted= %d\n\n",total);
	printf("PTI=%d\n\nPMLN=%d\n\nPPP=%d\n\nMQM=%d\n\nJI=%d\n",countPTI,countPmln,countPPP,countMQM,countJI);
	printf("**************************************************************\n");
	if(countPTI>countPmln && countPTI>countPPP && countPTI>countMQM && countPTI>countJI){
		printf("\nPTI candidate is on leading\n\n");
	    }
	else if(countPmln>countPTI && countPmln>countPPP && countPmln>countMQM && countPmln>countJI){
		printf("\nPmln candidate is on leading\n\n");
		}
	else if(countPPP>countPTI && countPPP>countPmln && countPPP>countMQM && countPPP>countJI){
		printf("\nPPP candidate is on leading\n\n");
		}
	else if(countMQM>countPTI && countMQM>countPPP && countMQM>countPmln && countMQM>countJI){
		printf("\nMQM candidate is on leading\n\n");
		}
	else if(countJI>countPTI && countJI>countPPP && countJI>countMQM && countJI>countPmln){
		printf("\nJI candidate is on leading\n\n");
		}
	else{
		printf("\nUndecidable condition\n\n");
	}		
    printf("**************************************************************\n");					
	fclose(fptrCnt);	
    printf("Enter Any Key To Proceed \n");
    getche();
    system("cls");

}
#include<stdio.h>
#include<stdlib.h>
#define MAX_STUDENTS 10

typedef struct student {
    char* name;
    int roll;
    char telephone[11];
    char * address;
} student;
typedef struct sreg {
    int count;
    student *arrStudPtr[MAX_STUDENTS];
} sreg;
struct Student *createStudentRecord(){
    student *s1 = (student *)malloc(sizeof(student));
    // sreg *sr = (sreg *)malloc(sizeof(sreg));
    if(s1 == NULL){
      printf("Memory allocation unsuccessful\n");
      return 0;
    }

    char name[20];
    printf("enter name:");
    fgets(name,sizeof(name),stdin);
    name[strcspn(name,"\n")] = 0;
    getchar();
    s1->name = (char *)malloc(strLen(name) +1);
    if(!s1->name){
      free(s1);
      return NULL;
    }
    printf("Enter roll number: ");
    scanf("%d", &s1->roll);
    
    if (!s1->roll) {
        free(s1->name);
        free(s1);
        return NULL;
    }
    // getchar(); // clear newline
    char tel[11];
    printf("Enter 10-digit telephone number: ");
    fgets(tel, sizeof(tel), stdin);
    s1->telephone[strcspn(s1->telephone, "\n")] = 0;
    getchar();

    printf("Enter address: ");
    s1->address = (char*)malloc(strlen(s1->address) + 1);
    fgets(s1->address, sizeof(s1->address), stdin);
    s1->address[strcspn(s1->address, "\n")] = 0;
    
    
    if (!s1->address) {
        free(s1->name);
        free(s1);
        return NULL;
    }
    return s1;
}
struct student *createStudentRecordFromFile(FILE *fp){
   char name[20],tel[20],address[20];
   int roll;

   if(fscanf(fp," %[^\n]",name)!= 1)
    return NULL;
   if(fscanf(fp," %l0s",tel)!= 1)
    return NULL;
   if(fscanf(fp,"%d",&roll) != 1)
    return NULL;
    
    return NULL;
   
}
// void freeStudentRecord(Student * sp) – frees the dynamically allocated memory for the
// Student record.
// void freeStudentRecord(struct Student *sp){
  
//   if (!sp) return;{
//     free(sp->name);
//     free(sp->address);
//     free(sp);
//   }


// }
// void freeStudentRecord(struct student *sp) {

// }
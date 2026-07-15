#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define m 15
struct student{
    char name[20];
    int roll;
    char telephone[11];
    char address[30];
};
struct SReg {
    int count;
    struct student pupil[m];
};


int add(struct SReg *sr, struct student s){
    if(sr->count >= m ){
        printf("student limit exceeded");
        return 0;
    }
    sr->pupil[sr->count++] = s;
    printf("student successfully added");
    return 1;
}
struct student get(struct SReg *sr, int r){
    for(int i=0;i<sr->count;i++){
        if(sr->pupil[i].roll == r){
            printf("Student with roll %d is present in the register.",r);
            return sr->pupil[i];
        }
    }
    printf("Student is not present in the register.");
}
int delete(struct SReg *sr, int r){
    if(sr->count == 0){
        printf("No element present to delete");
        return 0;
    }
    
    sr->count -- ;
    printf("element successfully removed");
    return 1;
}
int modify(struct SReg *sr, int roll){

    if(sr->count == 0){
        printf("No element present in the array.");
        return 0;
    }
    for(int i=0;i<sr->count;i++){
        if(sr->pupil[i].roll == roll){

            printf("Taking inputs");
            printf("MENU\n1.Input name\n2.Input telephone number\n3.Input address\n4.Exit\n");

            int ch;
            scanf("%d",&ch);

            while (1){
                switch(ch){
                    case 1:{
                        char nm[20];
                        fgets(nm,sizeof(nm),stdin);
                        getchar();
                        break;
                    }
                    case 2:{
                        char telphn[20];
                        fgets(telphn,sizeof(telphn),stdin);
                        getchar();
                        break;
                    }
                    case 3:{
                        char address[20];
                        fgets(address,sizeof(address),stdin);
                        getchar();
                        break;
                    }
                    case 4:{
                        exit(1);
                        break;
                    }
                    default:{
                        printf("Invalid input");
                        break;
                    }
                }
            }
        }
    }
    printf("Element is not present in the array.");
    return 0;
}

void sortStudents(struct SReg *sr){

    if(sr->count == 0){
        printf("No element present.");
    }
    for(int i = 0;i<(sr->count-1);i++){
        for(int j=i+1;j<sr->count;j++ ){
            if(strcmp(sr->pupil[i].name ,sr->pupil[j].name) >0){
                struct student temp = sr->pupil[j];
                sr->pupil[j] = sr->pupil[i];
                sr->pupil[i] = temp;
            }
        }
    }
}
int getCount(struct SReg *sr){
    return sr->count;
}
void export(struct SReg *sr, char fname[]){
    FILE *fp = fopen(fname, "w");
    if (fp == NULL) {
        printf("Could not open file %s for writing.\n", fname);
        return;
    }

    for (int i = 0; i < sr->count; i++) {
        fprintf(fp, "%s,%d,%s,%s\n",sr->pupil[i].name,sr->pupil[i].roll,sr->pupil[i].telephone,sr->pupil[i].address);
    }
    fclose(fp);
    printf("Student data exported to %s successfully.\n", fname);

}
void load(struct SReg *sr, char fname[]){
    FILE *fp = fopen(fname, "r");
    if (fp == NULL) {
        printf("Could not open file %s for reading.\n", fname);
        return;
    }
    struct student temp;
    sr->count = 0;
    while (fscanf(fp, "%l9[^,],%d,%10[^,],%19[^\n]\n",
                  temp.name, &temp.roll, temp.telephone, temp.address) == 4) {
        if (sr->count < m) {
            sr->pupil[sr->count++] = temp;
        } else {
            printf("Maximum student limit reached while loading.\n");
            break;
        }
    }
}
int main(){

    printf("---MENU---\n1.Add\n2.Search\n3.Delete\n4.Modify\n5.SortStudents\n6.GetCount\n7.export\n8.Load\n9.Exit\n");
    struct SReg rg;
    rg.count = 0;

    while(1){
        printf("Enter choice:");
        int choice;
        scanf("%d",&choice);
        getchar();

        switch(choice){

            case 1:{

                struct student s1;

                char name[30];
                printf("Enter name:");
                fgets(name,sizeof(name),stdin);
                strcpy(s1.name,name);
                s1.name[strcspn(s1.name, "\n")] = '\0'; 

                int roll;
                printf("Enter roll:");
                scanf("%d",&roll);
                clearInputBuffer();
                s1.roll = roll;

                char telephone[11];
                printf("Enter telephone:");
                fgets(telephone,sizeof(telephone),stdin);
                strcpy(s1.telephone,telephone);
                s1.telephone[strcspn(s1.telephone, "\n")] = '\0'; 

                char address[30];
                printf("Enter address:");
                fgets(address,sizeof(address),stdin);
                strcpy(s1.address,address);
                s1.address[strcspn(s1.address, "\n")] = '\0'; 

                add(&rg,s1);
                break;
            }

            case 2:{

                int r;
                printf("Enter roll to be searched");
                scanf("%d",&r);
                get(&rg,r);
                break;

            }
            case 3:{

                int r;
                printf("Enter roll to be deleted");
                scanf("%d",&r);
                delete(&rg,r);
                break;

            }
            case 4:{

                int r;
                printf("Enter roll to be modfied");
                scanf("%d",&r);
                modify(&rg,r);
                break;

            }
            case 5:{
                sortStudents(&rg);
                break;
            }
            case 6:{
                getCount(&rg);
                break;
            }
            case 7:{
                char fname[45];
                printf("Enter filename: ");
                scanf("%s",&fname);
                load(&rg, fname);
                break;
            }
            case 8:{
                char fname[45];
                printf("Enter filename: ");
                scanf("%s",&fname);
                load(&rg, fname);
                break;
            }
            case 9:{
                exit(1);
                return 0;
                break;
            }
            default:{
                printf("Invalid input\n");
                break;
            }
        }
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *toml_parse(char buff[]);

int main(int argc, char const *argv[])
{
    /*
    file.toml -> FILE* data -> toml_parse(file.toml, data) ->
    // find the table 'champion'
    // find name inside of champion and return value
    char *value = find_string(data, "champion", "name");
    printf("%s", &value); // prints "vayne"
     ree(data);
     
    Write a function that examines the file and creates a struct
    based on the number of members in a table?
     
    if lastchar == \n
     
     
    // checks last char and size of string
    int pos = strlen(b);
   	printf("%d characters long. Last char is %c\n", pos, buff[pos-1]);
	
	// removes new lines at the end of fgets
   	while(fgets(buff, sizeof(buff), data) != NULL) {
    	int pos = strlen(b);
       	if(buff[pos-1] == '\n'){
        	strncat(result, buff, pos-1);
        }
    }


   	 i need to iterate through keywords
   	 for example:
   	 if buff[pos] == '['
   	 for(int i = 0; i < 99; i++) {
		if(buff[pos+i] != ']') {
		}
		else
			strncat(result, buff, pos+i)
   	 }
	this would (ideally) store the data in-between the two brackets [ and ]

	IDEA:

	Parse on line at a time.
	toml_parse(buff)
	if buff[0] starts with [ && buff[1] starts with [
	make

     */
    
    // make sure there's at least a file to parse
    if(argc <= 1) {
        perror("Error: Expected arguments.\nUseage: ./toml <filename.toml>\n");
        return -1;
    } else if(argc > 2) {
        perror("Error: Too many arguments.\nUseage: ./toml <filename.toml>\n");
        return -1;
    }
    
    
    // begin reading data
    FILE *data;
    // buff holds initial toml data
    char buff[1024]; // TODO: reallocate size after fopen()
    char *b = buff; // allows me to read the strlen of buff
    // result holds toml data without formatting
    char result[1024] = "";
    
    data = fopen(argv[1], "r");
    if(!data){
        perror("Error: File failed to open.\n");
        return -1;
    } 
    else {
    // all this does is remove newlines from toml files so that parsing them is easier?
    // if first char == '[' take the value and store as table name
    // if char after ']' is not ']' take the value and store as key name
    // if last char == '"' take the value and store as string_value
    // if last char is anything else, store it as int_value
    	while(fgets(buff, sizeof(buff), data) != NULL) {
    	printf("%s", toml_parse(buff));
    	}
    	if (ferror(data))
    		printf("Error: Unable to read data.\n");
    	else if (feof(data)){
    		//printf("\n"); // for clarity
    	}
    		fclose(data);
    		return 0;
    
	}
}	

char *toml_parse(char buff[]) {
    char *buff_ptr = buff;
    long length = strlen(buff_ptr);
    
    for(int i = 0; i < length; i++){
        if(buff[i] == '[' ) {
            if (buff[i+1] == '[') {
                printf("Array table detected.\n");
                i++; // add 1 to i so it doesn't scan the next char again
                // array table
            }
            else {
                printf("Regular table detected.\n");
                // regular table
                while(buff[i] != ']' && buff[i] != '\n') {
                    //do some fancy code to throw the remaining chars in an array.
                    i++;
                }
                if (buff[i] == ']')
                {
                    //printf("end table detected.\n");
                    return "end table ] keyword found\n";
                } else if (buff[i] == '\n') {
                    //perror("Error: new line found before ending bracket.\n");
                    return "failed";
                }
            }
        }    
    }
    
    return "success";
}
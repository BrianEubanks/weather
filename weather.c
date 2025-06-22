#include <stdlib.h>
#include <stdio.h>

char* tags[] = {
    "<title>",
    "<location>",
    "<station_id>",
    "<latitude>",
    "<longitude>",
    "<observation_time>",
    "<weather>",
    "<temperature_string>",
    "<relative_humidity>",
    "<wind_string>",
    "<pressure_string>",
    "<dewpoint_string>",
    "<heat_index_string>" };

char* taglabels[] = {
    "\n",
    "",
    "",
    "Lat: ",
    "Lon: ",
    "\n",
    "",
    "",
    "\nHumidity: ",
    "Wind Speed: ",
    "Barometer: ",
    "Dewpoint: ",
    "Heat Index: "
};
    

int main(int argc, char** argv){
    //printf("start\n");
    //printf("sizeof: %lu\n",sizeof(tags)/sizeof(char*));
    //printf("\n");

    system("clear");

    system("curl https://forecast.weather.gov/xml/current_obs/KATT.xml -s -o  katt.xml");

    int tagcount = sizeof(tags)/sizeof(char*);    
    char cmd[100];

    for (int i = 0; i < tagcount; i++){
	
	sprintf(cmd,"sed 's/</\\n</g' katt.xml | grep '%s' | sed 's/%s//g'\n",tags[i],tags[i] );

	printf("%s",taglabels[i]);
	fflush(stdout);
    	system(cmd );


    }
    
    printf("\n\n");
}

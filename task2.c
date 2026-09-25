# include <stdio.h>

float convert_temp(float temperature, char current_scale, char desired_scale);

int main(){
    float temperature;
    char temp_scale;
    char convert_scale;

    // get user input
    printf("Enter the Temperature Value: ");
    scanf("%f", &temperature);

    printf("Enter the original scale (C, F, or K): ");
    scanf(" %c",&temp_scale);

    printf("Enter the scale to convert to (C, F, or K): ");
    scanf(" %c", &convert_scale);

    // prints the user's desired temp
    printf("The desired temp is: %.2f %c\n", convert_temp(temperature, temp_scale, convert_scale), convert_scale);
    temperature = convert_temp(temperature, temp_scale, 'C');

    if(temperature < 0){
        printf("Temperature Category: Freezing\n");
        printf("Weather Advisory: Bring a coat!");
    }
    else if(temperature < 10){
        printf("Temperature Category: Cold\n");
        printf("Weather Advisory: Bring a jacket!");
    }
    else if(temperature < 25){
        printf("Temperature Category: Comfortable\n");
        printf("Weather Advisory: Enjoy the outdoors!");
    }
    else if(temperature < 35){
        printf("Temperature Category: Hot\n");
        printf("Weather Advisory: Drink lots of water!");
    }
    else{
        printf("Temperature Category: Extreme Heat\n");
        printf("Weather Advisory: Stay indoors!");
    }
    return 0;
}

float convert_temp(float temperature, char current_scale, char desired_scale){
    // turns everything to Fahrenheit 
    if(current_scale != 'F'){
        if (current_scale == 'C'){
            temperature = (temperature * (9.0/5.0)) + 32;
        }
        else{ // has to be kelvin
            temperature =((temperature - 273.15 ) * 9.0/5.0) + 32;
        }
    }

    // converts from fahrenheit to desired scale
    if(desired_scale == 'F'){
        return temperature;
    }
    else if (desired_scale == 'C')
    {
        return (temperature-32)*(5.0/9.0);
    }
    else{
        return (temperature-32) * (5.0/9.0) + 273.15;
    }
    
}
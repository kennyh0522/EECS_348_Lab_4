# include <stdio.h>

float convert_temp(float temperature, char current_scale, char desired_scale);

int main(){
    float temperature;
    char temp_scale;
    char convert_scale;

    printf("Enter the Temperature Value: ");
    scanf("%f", &temperature);

    printf("Enter the original scale (C, F, or K): ");
    scanf(" %c",&temp_scale);

    printf("Enter the scale to convert to (C, F, or K): ");
    scanf(" %c", &convert_scale);


    printf("The desired temp is: %.2f\n", convert_temp(temperature, temp_scale, convert_scale));
    return 0;
}

float convert_temp(float temperature, char current_scale, char desired_scale){
    // turns everything to Fahrenheit 
    if(current_scale != 'F'){
        if (current_scale == 'C'){
            temperature = (temperature * (9/5)) + 32;
        }
        else{ // has to be kelvin
            temperature =((temperature - 273.15 ) * 9/5) + 32;
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
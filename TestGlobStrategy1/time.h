int *worlds_time(int hour_start, int hour_end, int hours, int days, int time_speed)
{
	if (hour_end - hour_start > 2000 * (1.25 - 0.25 * time_speed))
	{
		hours++;
		hour_start = 0;
	}
	if (hours == 24)
	{
		days++;
		hours = 1;
	}
	int hours_and_days[3] = { hour_start, hours, days };
	return hours_and_days;
}
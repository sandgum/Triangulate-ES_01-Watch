# How this UI project works

* After a lot of going back and forth, this UI uses EEZ studio as its drag and drop editor.
* Since EEZ Studio cannot support multiple displays in one project (The ES_01 has three displays), each display gets its own EEZ Studio project.
* These will be exported (once done) and have custom logic added to the C files which links events happening on the main screen to changes on the two OLEDS.
* There will be a bunch of other stuff added to the C code, including wiring in all the variables and setting callback functions for haptics.

# Implemented features

* Watch face showing:
  * Time
  * Date
  * Heart rate
  * Altitude
  * Step count for today
* 3 menu pages with 12 "apps" in total
  * ### Workout app:
    * 6 different workout types
      * Run
      * Walk
      * Cycle
      * HIIT
      * Yoga
      * Other
    * Statistics based on previous workouts
      * Zoomable graph showing activity over time
      * Top three favourite workouts, ranked by number of times done
    * Multipurpose counter
    * Workout sensor data
      * Heart rate
      * Estimated calories
      * Reps/distance travelled
    * After workout statistics
      * Zoomable graphs for:
        * Heart rate over time
        * Calories over time
        * Distance/reps over time
      * Average heart rate
      * Total calories burnt
  * ### Barometer app:
    * Current altitude
    * Average altitude for today
    * Zoomable graph for altitude over time
    * Current air pressure
    * Average air pressure for today
    * Zoomable graph for air pressure over time
  * ### Activity stats app:
    * Total step count, calories, activity time for today
    * Portion of daily step, calorie, activity goal completed
    * Zoomable graph for:
      * Step count over time
      * Calorie count over time
      * Activity over time
  * ### Vitals app:
    * Current heart rate, SpO2
    * Resting heart rate
    * Average SpO2
    * Zoomable graph showing heart rate, SpO2
  * ### Weather app:
    * Current temperature from iPhone WeatherKit
    * Current temperature measured by onboard sensor
    * Min/max temperatures for today (WeatherKit)
    * Current weather conditions (WeatherKit)
    * Forecasted temperature, weather conditions for the rest of the day (WeatherKit)
    * Forecasted min/max temperatures, weather conditions for next 10 days (WeatherKit)
  * ### Notifications:
    * Shows an indefinite number of notifications in the form of pages of four
    * App, title and text content of each notification
    * Tapping a notification opens an extended notification view, where more content text is shown
    * Notifications show an extended view when new notifications arrive
    * Specialised notification view for calls, with the option to decline or accept on phone
  * ### Timekeeping app:
    * Stopwatch
      * All logic is integrated using EEZ Flow
      * Stopwatch can be stopped, resumed and reset
      * Up to 99h 59m 59s counting
      * Arc to show seconds
    * Timer
      * All logic is implemented using EEZ Flow
      * Rollers for hours, minutes and seconds
      * Values on roller automatically update with countdown
      * Timer continues in the background
      * End of timer pop-up which shows upon completion, no matter where in the UI the user is
  * ### Timetable app:
    * Shows an arbitrary number of timetable events for a single day on a roller
    * Shows all timetable events for each day of the week
    * Editing timetable events will happen through the iPhone app
    * Timetable event popup which appears a set period of time before each event


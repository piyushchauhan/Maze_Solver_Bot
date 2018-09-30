# Maze_Solver_Bot
It is a simple Maze solver bot.
# Algorithm
<ol type = "1">
<li>Look for possible open paths.</li>
<li>If distance from any of the side ultrasonic sensor is greater than 10cm: Halt and again calculate the distances from all the sensors(implying that an intersection is encountered)</li>
<li>If the bot sees
  <ol type = "A">
    <li>Plus intersection: Move forward</li>
    <li>T intersection: Move left</li>
    <li>Left only: Move left</li>
    <li>Right only: Move right</li>
  </ol>
</li>
</ol>
# Important Note
Delays are very important as they help in effective reversal and desicion checks

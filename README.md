# Djikstra's Algorithm

1) Ten instances are included.
   
      input_[1-10].txt:         the input file;
   
      output_[1-10].txt:        the correct output file;

2) Compile MainTest to test data files:
      `g++ -std=c++11 MainTest.cpp -o djikstras`

3) You are encouraged to check time, memory:
   
      /usr/bin/time -v -o ${LOG_FILE} ./djikstras ${input_[1-10].txt} > ${result_[1-10].txt}
   
      for i in {1..10}; do /usr/bin/time -v -o "./GeneratedLogs/Log_$i.txt" ./djikstras "./Inputs/input_$i.txt" > "./GeneratedResults/result_$i.txt";done


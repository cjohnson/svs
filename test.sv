timeunit 10ps / 1fs;

module mux2to1(input logic test);
  timeprecision 1fs;
endmodule

module mux4to1(input logic test);
  timeunit 10ps; timeprecision 1fs;
endmodule

module mux8to1(input logic test);
  timeprecision 1fs; timeunit 10ps;
endmodule

module tb;
  bit a;

  initial begin
    a = 1'h0;
    $display("This is scheduled at the beginning of simulation.\n");
  end

  initial begin
    $display("This is also scheduled at the beginning of simulation.\n");
    $display("The order between execution of me and the other guy is non-deterministic.\n");
  end
endmodule

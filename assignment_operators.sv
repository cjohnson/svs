module top_module(
    input clock,
    input reset);

    logic [63:0] state, next_state;

    always_comb begin
        next_state = state;
        next_state += 1;
        next_state -= 1;
        next_state *= 5;
        next_state /= 4;
        next_state %= 17;
        next_state &= 4'hbeef;
        next_state |= 4'habeb;
        next_state <<= 2;
        next_state >>= 2;
        next_state <<<= 2;
        next_state >>>= 2;
        ++next_state;
        next_state++;
        --next_state;
        next_state--;
    end

    always @(posedge clock) begin
        if (reset) begin
            state <= 4;
        end else begin
            state <= next_state;
        end
    end
endmodule

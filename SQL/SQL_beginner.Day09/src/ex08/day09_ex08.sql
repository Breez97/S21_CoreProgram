CREATE OR REPLACE FUNCTION fnc_fibonacci(IN pstop INTEGER DEFAULT 10) RETURNS TABLE(fibonacci_number INTEGER) AS
$$
BEGIN
    RETURN QUERY
    WITH RECURSIVE fib AS (
        SELECT 
			0 AS fib_current, 
			1 AS fib_next
        UNION ALL
        SELECT 
			fib_next AS fib_current, 
			fib_current + fib_next AS fib_next
        FROM fib
        WHERE fib_next < pstop
    )
    SELECT fib_current AS fibonacci_number FROM fib;
END;
$$ LANGUAGE plpgsql;

-- SELECT * FROM fnc_fibonacci(100);
-- SELECT * FROM fnc_fibonacci();

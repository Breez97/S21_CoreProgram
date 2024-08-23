CREATE OR REPLACE FUNCTION func_minimum(arr NUMERIC[]) RETURNS TABLE (min_value NUMERIC) AS
$$
DECLARE
    min_value NUMERIC;
BEGIN
    min_value := arr[1];
    FOR i IN 2..array_length(arr, 1) LOOP
        IF arr[i] < min_value THEN
            min_value := arr[i];
        END IF;
    END LOOP;
    RETURN QUERY SELECT min_value::NUMERIC;
END;
$$ LANGUAGE plpgsql;

-- SELECT func_minimum(VARIADIC arr => ARRAY[10.0, -1.0, 5.0, 4.4]);
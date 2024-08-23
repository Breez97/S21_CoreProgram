CREATE OR REPLACE VIEW v_symmetric_union AS
	WITH R AS (
		SELECT person_id FROM person_visits 
		WHERE visit_date = '2022-01-02'
	),
	S AS (
		SELECT person_id FROM person_visits 
		WHERE visit_date = '2022-01-06'
	),
	R_minus_S AS (
		SELECT * FROM R
		EXCEPT
		SELECT * FROM S
	),
	S_minus_R AS (
		SELECT * FROM S
		EXCEPT
		SELECT * FROM R
	)
	
	SELECT * FROM R_minus_S
	UNION ALL
	SELECT * FROM S_minus_R
	ORDER BY 1;
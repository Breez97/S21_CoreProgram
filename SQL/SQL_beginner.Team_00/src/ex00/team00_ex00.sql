CREATE TABLE IF NOT EXISTS graph_nodes (
	point1 VARCHAR NOT NULL,
	point2 VARCHAR NOT NULL,
	cost INT NOT NULL
);

INSERT INTO graph_nodes (point1, point2, cost)
VALUES
	('a', 'b', 10),
	('a', 'c', 15),
	('a', 'd', 20),
	('b', 'a', 10),
	('b', 'c', 35),
	('b', 'd', 25),
	('c', 'a', 15),
	('c', 'b', 35),
	('c', 'd', 30),
	('d', 'a', 20),
	('d', 'b', 25),
	('d', 'c', 30);

CREATE OR REPLACE VIEW result_tour AS
	WITH RECURSIVE paths AS (
	    SELECT
	        point1 AS current_point,
	        point2 AS next_point,
	        cost AS total_cost,
	        point1 || ',' || point2 AS full_path,
	        1 AS level
	    FROM graph_nodes
	    WHERE point1 = 'a'
	    UNION ALL
	    SELECT
	        p.next_point AS current_point,
	        g.point2 AS next_point,
	        p.total_cost + g.cost AS total_cost,
	        p.full_path || ',' || g.point2 AS full_path,
	        p.level + 1 AS level
	    FROM paths p
	    JOIN graph_nodes g ON p.next_point = g.point1
	    WHERE
	        (p.level < 3 AND p.full_path NOT LIKE '%' || g.point2 || '%')
	        OR
	        (p.level = 3 AND g.point2 = 'a')
	        AND
	        (p.level < 5)
	)
SELECT *
FROM paths
WHERE level = 4;

SELECT total_cost, '{' || full_path || '}' AS tour
FROM result_tour
WHERE total_cost = (SELECT MIN(total_cost) FROM result_tour)
ORDER BY total_cost, tour;
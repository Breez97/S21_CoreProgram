WITH currency_last_rate_to_usd AS (
	SELECT
		cr.id,
		cr.name,
		cr.rate_to_usd
	FROM currency cr
	WHERE (cr.id, cr.updated) IN (
		SELECT 
			cr2.id, 
			MAX(cr2.updated)
		FROM currency cr2
		GROUP BY cr2.id
    )
)

SELECT
	COALESCE(us.name, 'not defined') AS name,
	COALESCE(us.lastname, 'not defined') AS lastname,
	bl.type AS type,
	SUM(COALESCE(bl.money, 0)) AS volume,
	COALESCE(clrtu.name, 'not defined') AS currency_name,
	COALESCE(clrtu.rate_to_usd, 1) AS last_rate_to_usd,
	(SUM(COALESCE(bl.money, 0)) * COALESCE(clrtu.rate_to_usd, 1))::numeric AS total_volume_in_usd
FROM balance bl
LEFT JOIN "user" us ON us.id = bl.user_id
LEFT JOIN currency_last_rate_to_usd clrtu ON clrtu.id = bl.currency_id
GROUP BY
	us.id,
	us.name,
	us.lastname,
	bl.type,
	clrtu.name,
	clrtu.rate_to_usd,
	clrtu.id
ORDER BY
	name DESC,
	lastname,
	type;
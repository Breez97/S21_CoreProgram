-- INSERT INTO currency VALUES (100, 'EUR', 0.85, '2022-01-01 13:29');
-- INSERT INTO currency VALUES (100, 'EUR', 0.79, '2022-01-08 13:29');

WITH balance_with_correct_date AS (
    SELECT
        b.user_id,
        b.money,
        b.currency_id,
        COALESCE(
            (SELECT MAX(c.updated)
             FROM currency c
             WHERE c.id = b.currency_id AND c.updated <= b.updated),
            (SELECT MIN(c.updated)
             FROM currency c
             WHERE c.id = b.currency_id AND c.updated > b.updated)
        ) AS updated
    FROM
        balance b
)

SELECT
    COALESCE(u.name, 'not defined') AS name,
    COALESCE(u.lastname, 'not defined') AS lastname,
    c.name AS currency_name,
    (corDate.money * c.rate_to_usd)::float AS currency_in_usd
FROM
    balance_with_correct_date corDate
    JOIN currency c ON corDate.updated = c.updated AND corDate.currency_id = c.id
    LEFT JOIN "user" u ON corDate.user_id = u.id
ORDER BY
    name DESC,
    lastname,
    currency_name;
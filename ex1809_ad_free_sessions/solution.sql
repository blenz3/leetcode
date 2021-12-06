# Write your MySQL query statement below
SELECT
    p.session_id
FROM
    Playback p LEFT JOIN Ads a ON
        p.customer_id = a.customer_id AND
        a.timestamp > p.start_time AND p.end_time
WHERE
    a.customer_id IS NULL

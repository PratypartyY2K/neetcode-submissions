SELECT 
    c.customer_id, 
    c.customer_name
FROM customers c
JOIN orders o 
    ON c.customer_id = o.customer_id
GROUP BY 
    c.customer_id, 
    c.customer_name
HAVING 
    SUM((o.product_name = 'A')::int) > 0
    AND SUM((o.product_name = 'B')::int) > 0
    AND SUM((o.product_name = 'C')::int) = 0
ORDER BY 
    c.customer_name ASC;
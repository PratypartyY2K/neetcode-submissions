-- Write your query below
select customers.name from customers
WHERE customers.id NOT IN (select orders.customer_id from orders WHERE customer_id IS NOT NULL)
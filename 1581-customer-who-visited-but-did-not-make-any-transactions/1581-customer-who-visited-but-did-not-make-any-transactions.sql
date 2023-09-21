# Write your MySQL query statement below

SELECT customer_id, COUNT(customer_id) as count_no_trans FROM Visits
LEFT JOIN Transactions
ON Visits.visit_id = Transactions.visit_id
WHERE transaction_id IS NULL
GROUP BY customer_id
ORDER BY count_no_trans DESC;
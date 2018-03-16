<?php

$names = ['John', 'Jack', 'Bobbie', 'Susie', 'Jeff'];


for ($i = 0; $i < 50; $i++) {
  db_query('INSERT INTO hamsters (name, weight, gender, habitat_id) VALUES (:vals)', [
    ':vals' => [
      $names[rand(0, 4)],
      rand(50, 200),
      (($i%2 == 0) ? 'male': 'female'),
      rand(1, 3),
    ],
  ]);
}
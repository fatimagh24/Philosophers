# Philosophers 🥢🍽️

## 🚀 Overview
The **Philosophers** project is a classic concurrency problem that simulates philosophers sitting around a table, alternating between **thinking** and **eating**.  
The goal is to manage **resource sharing (forks)** efficiently without causing **deadlocks** or **race conditions**, using **threads and mutexes** in C.

---

## 🛠 Features
- Simulates `n` philosophers sitting at a table
- Each philosopher:
  - Thinks
  - Eats (requires picking up two forks)
  - Sleeps
- Ensures:
  - No philosopher dies unnecessarily
  - No deadlocks occur
  - Accurate timing for each action
- Uses only allowed functions:
  - `pthread_create`, `pthread_detach`, `pthread_join`
  - `pthread_mutex_init`, `pthread_mutex_lock`, `pthread_mutex_unlock`, `pthread_mutex_destroy`
  - `gettimeofday`, `usleep`, `write`, `malloc`, `free`, `memset`, `printf`

---

## ⚡ Usage

```bash
# Compile the program
make

# Run the program
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

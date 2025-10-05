# Design a Parking Lot
In this, we explore the object-oriented design of a Parking Lot system, one of the most popular questions in technical interviews. This parking lot application aims to provide a comprehensive solution for efficiently managing a parking lot. It automates various processes, including vehicle entry, exit, and spot allocation, while also providing accurate information about parking lot occupancy and generating parking tickets.

## Requirements Gathering
In this step, we ask clarifying questions to narrow down the list of requirements, understand the constraints, and define the problem.

Here is an example of how a conversation between a candidate and an interviewer might unfold:
<details>
<summary>🗣️ <b>Click to view Interview Conversation</b></summary>

> 🧑‍💻 **Candidate:** What types of vehicles are supported by the parking lot?  
> 👨‍🏫 **Interviewer:** Three types — motorcycles, cars, and trucks.

---

> 🧑‍💻 **Candidate:** What parking spot types are available in the parking lot?  
> 👨‍🏫 **Interviewer:** Compact, regular, and oversized spots.

---

> 🧑‍💻 **Candidate:** How does the system determine which spot a vehicle should park in?  
> 👨‍🏫 **Interviewer:** The system assigns spots based on the vehicle’s size.

---

> 🧑‍💻 **Candidate:** Are parking tickets issued and charged at exit?  
> 👨‍🏫 **Interviewer:** Yes, tickets record vehicle details and entry time; fees are calculated at exit.

---

> 🧑‍💻 **Candidate:** How are parking fees calculated?  
> 👨‍🏫 **Interviewer:** Based on parking duration and vehicle size, with time-based rate variation.

</details>

Here are the key functional requirements we’ve identified:

- The parking lot has multiple parking spots, including compact, regular, and oversized spots.
- The parking lot supports parking for motorcycles, cars, and trucks.
- Customers can park their vehicles in spots assigned based on vehicle size.
- Customers receive a parking ticket with vehicle details and entry time at the entry point and pay a fee based on duration, vehicle size, and time of day at the exit point.

Below are the non-functional requirements:
- The system must scale to support large parking lots with many spots and vehicles.
- The system must reliably track spot assignments and ticket details to ensure accurate operations.




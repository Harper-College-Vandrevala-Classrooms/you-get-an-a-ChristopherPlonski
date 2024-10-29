[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/5q8vzIyP)
[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-2e0aaae1b6195c2367325f4f02e2d04e9abb55f0b24a779b69b11b9e10269abc.svg)](https://classroom.github.com/online_ide?assignment_repo_id=16814219&assignment_repo_type=AssignmentRepo)

# Gradebook

## Prerequisites
Requires C++14 or higher

## How-To
Create the 'Gradebook' object.
```
Gradebook gradebook = Gradebook();
```
Create 'Student' objects with a first name, last name, and student ID.
```
Student student = Student("Bob", "Smith", 11111);
```
Create 'Assignment' objects with assignment name and max score.
```
Assignment assignment = Assignment("Quiz 1", 100);
```
Add students/assignments using the 'add_new_student()' and 'add_new_assignment()' methods on the Gradebook object by passing their objects in the arguments.
```
gradebook.add_new_student(student);
gradebook.add_new_assignment(assignment);
```
Assign grades by using the 'try_give_student_grade_for_assignment()' method on the Gradebook object. Pass the student to grade, the assignment that will be graded, and the actual grade for the student. 
```
pair<bool,string> result = gradebook.try_give_student_grade_for_assignment(student, assignment, 43);
```
This function returns a 'pair<bool, string>', with the bool representing whether or not your passed parameters were valid (if the student/assignment wasn't previously added to the gradebook, it will be invalid), and the string representing the error/success message.


To get the report, use the 'get_report()' method on the Gradebook object.
```
gradebook.get_report()
```

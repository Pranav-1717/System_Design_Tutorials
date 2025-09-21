# DON'T REPEAT YOURSELF (DRY)
Code duplication feels quick at first — just copy, paste, done. But later, when a bug shows up, you’ll have to fix it in  different places. Which is very painful and time consuming.

**DRY = Write once, reuse everywhere.**<br>
**Fix it once → fixed everywhere**<br>
**Less bugs → more consistency**<br>

One function, one definition, one source of truth.

---

Imagine you’re building a signup form. You need to validate emails.
You’re in a hurry, so you do this:

```c++
// File: signup.cpp
bool validate_email_format(const string& email) {
    return email.find("@") != string::npos && email.find(".") != string::npos;
}
```
Later, you also need email validation for your login form. Copy-paste is tempting…

```c++
// File: login.cpp
bool validate_email_format(const string& email) {
    return email.find("@") != string::npos && email.find(".") != string::npos;
}
```
Looks fine, right? Wrong!
Now, if your validation logic changes (say, stricter domain check), you’ll have to update both places. Forget one, and you’ve just introduced a bug.

---

Instead, write the logic once:
```c++
// File: utils/email_validator.cpp
bool validate_email_format(const string& email) {
    return email.find("@") != string::npos && email.find(".") != string::npos;
}
```

Then reuse it everywhere:
```c++
#include "utils/email_validator.cpp"

bool signup_user(const string& email) {
    return validate_email_format(email);
}

bool login_user(const string& email) {
    return validate_email_format(email);
}
```
Now you’ve got one function to rule them all.

---


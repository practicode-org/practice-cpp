# Contributing to "Practice C++"

Your contribution is welcomed and appreciated. However, to provide consistency and high quality it's better to use common guidelines.

## Submitting changes

### Commit guidelines
1. Split your changes to complete and logically separated, but independent commits.

2. Use clang-format to maintain consistent formatting.

3. Use [conventional commits](https://www.conventionalcommits.org/en/v1.0.0-beta.4/) message style: `feat(sorting): add excercise: merge two sorted arrays`.
Used types are following:
- fix - when you fix code/issues
- feat - when you add new exercises, change build scripts
- docs - when you write new documentation, descriptions, exercise text
- typo - when you fix a small typo or a grammar mistake

The scope is optional and most often is an exercise category, such as "sorting" or "thread".

4. If it's something important, big, breaking, or not clear at first look, then please thoroughly describe your pull request: motivation, description, how you tested the change.

## Adding exercises
1. Currently, we aim for the medium complexity level. Although it's very subjective, we'll try to explain what we mean:
- a user knows how to use basic language patterns, how to compile, how to write, run and read unit tests, and how to use git
- the user has at least little or even professional experience in the language but wants to dwell into details, learn what has been omitted, or practice some uncommon features
- most exercises have a `plus` section that adds additional, but optional complexity
- the expected time frame for most of the tasks is less than an hour
- one topic (sorting, for instance) may have an easy exercise, a bunch of medium, and one or two complex exercises that would require more work

For now, we don't add links where to study, but later probably will.

2. Topics to choose are random, without following a particular linear study plan.

3. Style, structure, and formatting should match all other exercises. Template:
```
/*
[Optional description/introduction]
Task:
- ...
- ...

[Optional examples]
*/

Initial code. It may or may not compile. It may have tips in the comments.
```

4. Add additional information to your PR according to these questions:
- Subjective complexity: easy, medium, hard.
- What does it teach?
- Sample of a preferred/expected solution.
- Test environment.

## Reporting issues
Whenever you find an issue: an exercise is not working as intended or code does not compile on a supported platform (note that some files intentionally do not compile at first, and it's part of an exercise), simply [report the issue](https://github.com/practicode-org/practice-cpp/issues/new) via Github.

Sometimes, however, for small issues such as typos or grammar mistakes, it makes sense to just submit a pull request.

If you're pretty sure it's impossible to solve an exercise (following all the constraints), please, contact the [maintainer](email://yukigaru@gmail.com) via email.

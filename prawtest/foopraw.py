#/usr/local/lib
import praw

reddit = praw.Reddit('bot1',user_agent='some scraper')

for submission in reddit.subreddit('aww').hot(limit=10):
    print(submission.title)
    print(submission.score)
    print(submission.id)

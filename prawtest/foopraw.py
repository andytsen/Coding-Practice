#/usr/local/lib
import praw

reddit = praw.Reddit('bot1',user_agent='some scraper')

for submission in reddit.subreddit('leagueoflegends').hot(limit=11):
    if(submission.stickied == False):
        print(submission.title)
        print("\n")

class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        emailset = set()
        for email in emails:
            name, domain = email.split('@')
            name = name.replace(".", '')
            if '+' in name:
                name = name[:name.index('+')]
            email = '@'.join([name,domain])
            emailset.add(email)
        return len(emailset)
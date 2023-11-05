#include "../inc/Message.hpp"

Message::Message(int socket, std::string msg)
: socket(socket)
{
    parse(msg);
}

Message::~Message() {}

std::vector<std::string> split(std::string input, char delimiter)
{
    std::vector<std::string> answer;
    std::stringstream ss(input);
    std::string temp;
 
    while (getline(ss, temp, delimiter))
	{
        answer.push_back(temp);
    }
    return answer;
}

// trim from right
std::string& rtrim(std::string& s, const char* t = " \t\n\r\f\v")
{
    s.erase(s.find_last_not_of(t) + 1);
    return s;
}

const std::string &Message::getPrefix() const
{
	return (this->prefix);
}

const std::string &Message::getCommand() const
{
	return (this->command);
}

const std::vector<std::string> &Message::getArg() const
{
	return (this->argument);
}

int	Message::getSocket()
{
	return (this->socket);
}

void Message::parse(std::string msg)
{
    // space split -> 맨앞문자가 colon인지 확인 -> colon이면 prefix
	// 에러처리 뭐할지 ?
	
    rtrim(msg);

	std::vector<std::string> msg_split;
	msg_split = split(msg, ' ');
	int i = 0;
    if (msg[0] == ':')
	{
		this->prefix = msg_split[i++];
		this->command = msg_split[i++];
    }
    else
    {
		this->prefix = "";
		this->command = msg_split[i++];
    }
	for (; i < msg_split.size(); i++)
		this->argument.push_back(msg_split[i]);
}

Message::Message(int socket,
                 const std::string &prefix,
                 const std::string &command,
                 const std::vector<std::string> &argument)
        : socket(socket), prefix(prefix), command(command), argument(argument)
{}

void Message::setPrefix(const std::string &prefix)
{
    Message::prefix = prefix;
}

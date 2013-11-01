#include<string>
#include<set>
#include<vector>

class Folder;

class Message{
	friend class Folder;
	public:
		Message(const std::string &str = ""):
			contents(str) {}
		Message(const Message&);
		Message& operator=(const Message&);
		~Message();
	
		void save(Folder&);
		void remove(Folder&);
		std::vector<Folder*> get_folders();
		std::string print_message() {return contents;}
		void debug_print();
	private:
		std::string contents;
		std::set<Folder*> folders;

		void put_Msg_in_Folders(const std::set<Folder*>&);
		void remove_Msg_from_Folders();

		void addFldr(Folder *f) {folders.insert(f);}
		void remFldr(Folder *f) {folders.erase(f);}
};

class Folder{
	friend class Message;
public:
	~Folder();
	Folder(const Folder&);
	Folder& operator=(const Folder&);
	Folder(){}

	void save(Message&);
	void remove(Message&);

	std::vector<Message*> message();
	void debug_print();
private:
	typedef std::set<Message*>::const_iterator Msg_iter;
	std::set<Message*> msgs;

	void copy_msgs(const std::set<Message*>&);
	void empty_msgs();
	void addMsg(Message *m) {msgs.insert(m);}
	void remMsg(Message *m) {msgs.erase(m);}
};


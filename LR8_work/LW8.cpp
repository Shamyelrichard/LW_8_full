#include <iostream>
#include <string>

class Data {
private:
	int day;
	int month;
public:
	Data(int day_ = 0, int month_ = 0) {
		this->day = day_;
		this->month = month_;
	}
	int get_day() {
		return day;
	}
	int get_month() {
		return month;
	}
	void set_day(int new_day) {
		day = new_day;
	}
	void set_month(int new_month) {
		month = new_month;
	}
	Data operator + (const Data& alt) {
		int delta_day = (day + alt.day) % 30;
		int delta_month = month + alt.month + (day + alt.day) / 30;
		return Data{ delta_day, delta_month };
	}
	bool operator == (Data& alt) {
		if (day == alt.day && month == alt.month) {
			return 1;
		}
		return 0;
	}
};
std::ostream& operator <<(std::ostream& stream, Data& moment) {
	stream << "month - ";
	stream << moment.get_month() << "\t";
	stream << "day - ";
	stream << moment.get_day();
	return stream;
}


class Plant {
private:
	std::string name;
	int lifetime; // lifetime_in_days
	Data day_of_born;
public:
	Plant(std::string name_ = "Bob", int lifetime_ = 365, Data day_of_born_ = { 0, 0 }) {
		this->name = name_;
		this->lifetime = lifetime_;
		this->day_of_born = day_of_born_;
	}
	void set_name(std::string new_name) {
		name = new_name;
	}
	void set_lifetime(int new_lifetime) {
		lifetime = new_lifetime;
	}
	void set_day_of_born(Data new_day_of_born) {
		day_of_born = new_day_of_born;
	}
	std::string get_name() {
		return name;
	}
	int get_lifetime() {
		return lifetime;
	}
	Data get_day_of_born() {
		return day_of_born;
	}
	void print() {
		std::cout << "name - " << name << '\n' << "lifetime - " << lifetime << "\n" << "day when he/she was plant" << day_of_born << "\n";
	}
	void how_old_plant() {
		int years = lifetime / 365;
		int months = (lifetime - years * 365) / 30;
		int days = lifetime - years * 365 - months * 30;
		std::cout << "your plant lived for "; // << years << "years " << months << "months and " << days << "days";
		if (years > 0) {
			std::cout << years << " years ";
		}
		if (months > 0) {
			std::cout << months << " months ";
		}
		if (days > 0) {
			std::cout << days << " days ";
		}
		std::cout << "congrats" << "\n";
	}
};
class Flower : public Plant {
private:
	std::string name;
	int lifetime;
	Data day_of_born;
	Data bloom_starting;
	int bloom_duration;
public:
	Flower(std::string name_ = "Bob", int lifetime_ = 365, Data day_of_born_ = { 0, 0 }, Data bloom_starting_ = { 0, 0 }, int bloom_duration_ = 1) {
		this->name = name_;
		this->lifetime = lifetime_;
		this->day_of_born = day_of_born_;
		this->bloom_starting = bloom_starting_;
		this->bloom_duration = bloom_duration_;
	};
	void set_bloom_starting(Data new_bloom_data) {
		bloom_starting = new_bloom_data;
	}
	void set_bloom_duration(int new_b_d) {
		bloom_duration = new_b_d;
	}
	Data get_bloom_starting() {
		return bloom_starting;
	}
	int get_bloom_duration() {
		return bloom_duration;
	}
	void print() {
		std::cout << "name - " << name << '\n'
			<< "lifetime - " << lifetime << "\n"
			<< "day when he/she was plant " << day_of_born << "\n"
			<< "blosom starting in " << bloom_starting << "\n"
			<< "blossom will continue for " << bloom_duration << " days" << "\n";
	}
};

int main() {
	Plant one = { "nikita", 730, {1, 1} };
	one.print();
	one.how_old_plant();
	std::cout << "\n" << "\n" << "\n";
	Flower Rose = { "Abrogim", 1000, {0, 0}, {6, 0}, 344 };
	Rose.print();
	Rose.how_old_plant();
}
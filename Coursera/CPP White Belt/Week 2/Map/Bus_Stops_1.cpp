#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main() {
    int n, n_stops;
    string bus_name, bus_change_name, stop_name, request;
    map<string, vector<string>> bus_to_stops, stops_to_buses;
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        cin >> request;
        if (request == "NEW_BUS") {
            cin >> bus_name;
            cin >> n_stops;
            for (int i = 0; i < n_stops; ++i) {
                cin >> stop_name;
                bus_to_stops[bus_name].push_back(stop_name);
                stops_to_buses[stop_name].push_back(bus_name);
            }
        
        } else if (request == "BUSES_FOR_STOP") {
            cin >> stop_name;
            if (stops_to_buses.count(stop_name)) {
                for (const string& bus_name : stops_to_buses[stop_name]) {
                    cout << bus_name << " ";
                }
                cout << endl;
            } else {
                cout << "No stop" << endl;
            }

        } else if (request == "STOPS_FOR_BUS") {
            cin >> bus_name;
            if (bus_to_stops.count(bus_name)) {
                for (const string& stop_name : bus_to_stops[bus_name]) {
                    cout << "Stop " << stop_name << ": ";
                    if (stops_to_buses[stop_name].size() > 1) {
                        for (const string& bus_change_name : stops_to_buses[stop_name]) {
                            if (bus_change_name != bus_name) {
                                cout << bus_change_name << " ";
                            } 
                        }
                    } else {
                        cout << "no interchange";
                    }
                    
                    cout << endl;
                }
            } else {
                cout << "No bus" << endl;
            }
        } else if (request == "ALL_BUSES") {
            if (bus_to_stops.size()) {
                for (const auto& [bus_name, stops_list] : bus_to_stops) {
                    cout << "Bus " << bus_name << ": ";
                    for (const string& stop_name : stops_list) {
                        cout << stop_name << " ";
                    }
                    cout << endl;
                }
            } else {
                cout << "No buses" << endl;
            }
            
        }
        /*
        } else if (request == "STOPS_FOR_BUS") {
            cin >> bus_name;
            if (bus_to_stops.count(bus_name)) {
                cout << "Bus " << bus_name << ": ";
                for (const string& stop_name : bus_to_stops[bus_name]) {
                    cout << stop_name << " ";
                }
                cout << endl;
            } else {
                cout << "No bus" << endl;
            }
        } else if (request == "BUSES_FOR_STOP") {

        }*/
    }
    return 0;
}
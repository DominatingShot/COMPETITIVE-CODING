class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> graph; // Create a graph using a map of strings to multiset of strings.
        vector<string> result; // Initialize a vector to store the result itinerary.

        if (tickets.size() == 0)
            return result; // If there are no tickets, return an empty result.

        // Build the graph from the given list of tickets.
        for (auto ticket : tickets) {
            graph[ticket[0]].insert(ticket[1]); // Add the destination to the multiset for the source airport.
        }

        stack<string> s; // Create a stack to perform depth-first search.

        s.push("JFK"); // Start with the JFK airport as the initial source.

        while (!s.empty()) {
            string src = s.top(); // Get the top airport from the stack.

            if (graph[src].empty()) {
                // If there are no more destinations from the current airport, add it to the result.
                result.push_back(src);
                s.pop(); // Remove the airport from the stack.
            } else {
                auto dst = graph[src].begin(); // Get the first destination from the multiset.
                s.push(*dst); // Push the destination onto the stack.
                graph[src].erase(dst); // Remove the destination from the multiset.
            }
        }

        reverse(result.begin(), result.end()); // Reverse the result to get the correct itinerary order.
        return result; // Return the final itinerary.
    }
};

import React, { useState, useEffect } from 'react';

interface Message {
  type: string;
  state: string;
  message: string;
}

const agentTypes = ['All', 'Staff', 'Sales', 'Buyer', 'Stocker'];

const App: React.FC = () => {
  const [messages, setMessages] = useState<Message[]>([]);
  const [selectedAgentType, setSelectedAgentType] = useState<string>('Staff');

  useEffect(() => {
    fetchData(selectedAgentType);
  }, [selectedAgentType]);

  const fetchData = async (agentType: string) => {
    try {
      const response = await fetch(`http://services.tatmangames.com/agent/messages?agentType=${agentType}`);
      if (!response.ok) {
        throw new Error('Failed to fetch data');
      }
      const data = await response.json();
      setMessages(data.messages);
    } catch (error) {
      console.error('Error fetching data:', error);
    }
  };

  const sortMessagesByState = () => {
    const sortedMessages = [...messages].sort((a, b) => {
      if (a.state < b.state) return -1;
      if (a.state > b.state) return 1;
      return 0;
    });
    setMessages(sortedMessages);
  };

  const handleAgentTypeChange = (event: React.ChangeEvent<HTMLSelectElement>) => {
    setSelectedAgentType(event.target.value);
  };

  return (
      <div>
        <h1>Messages</h1>
        <div>
          <label htmlFor="agentType">Select Agent Type: </label>
          <select id="agentType" value={selectedAgentType} onChange={handleAgentTypeChange}>
            {agentTypes.map((type, index) => (
                <option key={index} value={type}>
                  {type}
                </option>
            ))}
          </select>
        </div>
        <button onClick={sortMessagesByState}>Sort by State</button>
        <ul>
          {messages.map((message, index) => (
              <li key={index}>
                <strong>Type:</strong> {message.type}, <strong>State:</strong> {message.state}, <strong>Message:</strong>{' '}
                {message.message}
              </li>
          ))}
        </ul>
      </div>
  );
};

export default App;

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
  const [isError, setIsError] = useState<boolean>(false);
  const [errorMessage, setErrorMessage] = useState<string>('');

  useEffect(() => {
    fetchData(selectedAgentType);
  }, [selectedAgentType]);

  const fetchData = async (agentType: string) => {
    try {
      if (agentType === 'All') {
        setIsError(true);
        setErrorMessage('All is not supported at this time');
        setMessages([]);
        return;
      }

      const response = await fetch(`https://services.tatmangames.com/agent/messages?agentType=${agentType}`,{
        method: "GET",
        headers: {
          "access-control-allow-origin" : "*",
          "Content-type": "application/json; charset=UTF-8"
        }});

      if (!response.ok) {
        setIsError(false);
        setErrorMessage('failed to fetch data');
        throw new Error('Failed to fetch data');
      }
      const data = await response.json();

      setIsError(false);
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

        {isError && (
            <div>
              {errorMessage}
            </div>
        )}

        {!isError && (
          <div>
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
       )}
      </div>
  );
};

export default App;

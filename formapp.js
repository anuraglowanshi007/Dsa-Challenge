import './App.css';
import { useState } from 'react';

function App() {
  const [formData, setFormData] = useState({
    firstName: "",
    lastName: "",
    email: "",
    comments: "",
    isvisible: true,
    mode: "",
    favCar: ""
  });

  function changeHandler(event) {
    const { name, value, checked, type } = event.target;
    setFormData(prevFormData => ({
      ...prevFormData,
      [name]: type === "checkbox" ? checked : value
    }));
  }

  function submitHandler(event) {
    event.preventDefault();
    console.log("Finally printing the entire form data ", formData);
  }

  return (
    <div className="App bg-gray-100 min-h-screen flex items-center justify-center p-4">
      <form onSubmit={submitHandler} className="bg-white p-6 rounded-lg shadow-lg w-full max-w-md">
        <h2 className="text-2xl font-bold mb-4">Contact Us</h2>
        
        <div className="mb-4">
          <label htmlFor="firstName" className="block text-sm font-medium text-gray-700">First Name</label>
          <input
            type="text"
            placeholder="First Name"
            onChange={changeHandler}
            name="firstName"
            value={formData.firstName}
            className="mt-1 block w-full border border-gray-300 rounded-md shadow-sm p-2 focus:ring-indigo-500 focus:border-indigo-500 sm:text-sm"
          />
        </div>
        
        <div className="mb-4">
          <label htmlFor="lastName" className="block text-sm font-medium text-gray-700">Last Name</label>
          <input
            type="text"
            placeholder="Last Name"
            onChange={changeHandler}
            name="lastName"
            value={formData.lastName}
            className="mt-1 block w-full border border-gray-300 rounded-md shadow-sm p-2 focus:ring-indigo-500 focus:border-indigo-500 sm:text-sm"
          />
        </div>
        
        <div className="mb-4">
          <label htmlFor="email" className="block text-sm font-medium text-gray-700">Email</label>
          <input
            type="email"
            placeholder="Enter your email"
            onChange={changeHandler}
            name="email"
            value={formData.email}
            className="mt-1 block w-full border border-gray-300 rounded-md shadow-sm p-2 focus:ring-indigo-500 focus:border-indigo-500 sm:text-sm"
          />
        </div>
        
        <div className="mb-4">
          <label htmlFor="comments" className="block text-sm font-medium text-gray-700">Comments</label>
          <textarea
            placeholder="Enter your comments here"
            onChange={changeHandler}
            name="comments"
            value={formData.comments}
            className="mt-1 block w-full border border-gray-300 rounded-md shadow-sm p-2 focus:ring-indigo-500 focus:border-indigo-500 sm:text-sm"
          />
        </div>
        
        <div className="mb-4 flex items-center">
          <input
            type="checkbox"
            onChange={changeHandler}
            name="isvisible"
            checked={formData.isvisible}
            className="h-4 w-4 text-indigo-600 focus:ring-indigo-500 border-gray-300 rounded"
          />
          <label htmlFor="isvisible" className="ml-2 block text-sm text-gray-900">Am I visible?</label>
        </div>
        
        <fieldset className="mb-4">
          <legend className="block text-sm font-medium text-gray-700">Mode</legend>
          <div className="mt-1">
            <div className="flex items-center mb-2">
              <input
                type="radio"
                onChange={changeHandler}
                name="mode"
                value="Online-Mode"
                id="Online-Mode"
                checked={formData.mode === "Online-Mode"}
                className="h-4 w-4 text-indigo-600 focus:ring-indigo-500 border-gray-300"
              />
              <label htmlFor="Online-Mode" className="ml-2 block text-sm text-gray-900">Online Mode</label>
            </div>
            <div className="flex items-center">
              <input
                type="radio"
                onChange={changeHandler}
                name="mode"
                value="Offline-Mode"
                id="Offline-Mode"
                checked={formData.mode === "Offline-Mode"}
                className="h-4 w-4 text-indigo-600 focus:ring-indigo-500 border-gray-300"
              />
              <label htmlFor="Offline-Mode" className="ml-2 block text-sm text-gray-900">Offline Mode</label>
            </div>
          </div>
        </fieldset>
        
        <div className="mb-4">
          <label htmlFor="favCar" className="block text-sm font-medium text-gray-700">Tell me about your favourite car</label>
          <select
            name="favCar"
            id="favCar"
            value={formData.favCar}
            onChange={changeHandler}
            className="mt-1 block w-full border border-gray-300 rounded-md shadow-sm p-2 focus:ring-indigo-500 focus:border-indigo-500 sm:text-sm"
          >
            <option value="Thar">Thar</option>
            <option value="Defender">Defender</option>
            <option value="Discovery">Discovery</option>
            <option value="Jaguar">Jaguar</option>
            <option value="Fortuner">Fortuner</option>
          </select>
        </div>
        
        <button className="w-full bg-indigo-600 text-white py-2 rounded-md hover:bg-indigo-700 focus:outline-none focus:ring-2 focus:ring-indigo-500 focus:ring-offset-2">
          Submit
        </button>
      </form>
    </div>
  );
}

export default App;

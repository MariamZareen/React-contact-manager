import React,{useState, useEffect} from 'react' 
import AddContacts from './AddContacts';
import './App.css';
import Contactlist from './Contactlist';
import Header from './Header';
function App(){
     const LOCAL_STORAGE_KEY='contacts'
    const [contacts, setContacts] = useState([]);
  
    
      const addContactHandler = (contact) => {
        console.log(contact);
        setContacts([...contacts,{id: crypto.randomUUID(),...contact}]);
      };
      
      const removeContactHandler=(id)=>{
             const newContactList=contacts.filter((contact)=>{
              return contact.id!=id;
             })
             setContacts(newContactList);
      }
      
       useEffect(()=>{
          const retriveContacts = JSON.parse(localStorage.getItem(LOCAL_STORAGE_KEY));
          if(retriveContacts) setContacts(retriveContacts)
        },[])
        
        useEffect(()=>{
          localStorage.setItem(LOCAL_STORAGE_KEY,JSON.stringify(contacts))
       },[contacts]);

       
    return(
        <div className='ui container' >
        <Header/>
        <AddContacts addContactHandler={ addContactHandler}/>
        <Contactlist contacts={contacts} getContactId={removeContactHandler}/>
        </div>
    )
}
 export default App;






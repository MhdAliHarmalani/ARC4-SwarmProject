//send_string_of_indexs_And_receive_weights and make list_of_Weight_index_of_names_of_edges_bot_can_choose
void send_string_of_indexs_And_receive_weights(){
  String String_weights,tmp="";
  int i;
  repeat_process://to goto here if message is bad and repeat_process of sending
 create_NamesAndIndex_of_edges_from_botWays() ; 
  Serial.println(String_of_indexs_list);
  list_of_Weight_index_of_names_of_edges_bot_can_choose.clear();
  while(!Serial.available());
  String_weights=Serial.readString();
  if(String_weights.substring(0,1).equals("W")){
  for(i=1;i<=String_weights.length();i++){
    if( String_weights[i] != ','  &&  i < String_weights.length()){
      tmp=tmp+String_weights[i];
      
    }
    else{
      //Serial.println(tmp);
      list_of_Weight_index_of_names_of_edges_bot_can_choose.push_back(tmp.toFloat());
      tmp="";
    }
  
  }
  }
  else{
    goto repeat_process;
  }
}
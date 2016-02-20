/*  <SecCrypt CPL V3R05>  */
 
//  by  snowcat  6/21/1997
//  whohave.c

inherit  F_CLEAN_UP;

void  listing  (object  who,  string  prefix,  string  arg)
{
	object  *ilist;
	int  j;

	if  (!  present  (arg,who))
		return;
	write  (prefix+who->query("name")+":");
	ilist  =  all_inventory(who);
	if  (!  ilist)
	      	return;
	j  =  sizeof(ilist);
	while  (j--)  {
		object  ob  =  ilist[j];
		string  *ids  =  ob->parse_command_id_list();
		if  (member_array(arg,  ids)  ==  -1)  {
			continue;
		}	
		write  ("  "+ob->short());
	}
	write  ("\n");
	j  =  sizeof(ilist);
	while  (j--)  {
		object  ob  =  ilist[j];
		listing  (ob,  "    "+prefix,arg);
	}
}

mixed  main(object  me,  string  arg,  int  remote)
{
	object  *ulist;
	int  i;

	if  (!  arg)
		return  notify_fail  ("指令格式  whohave  <id>\n");

	ulist  =  users();
	i  =  sizeof(ulist);
	while  (i--)  {
		listing  (ulist[i],  "    ",  arg);
	}
	return  1;
}

int  help  (object  me)
{
                write(@HELP
指令格式  :  whohave  <id>
  
可列出目前携带某个物品的玩家。
  
  
HELP
);
                return  1;
}

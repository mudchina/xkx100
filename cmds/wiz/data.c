/*  <SecCrypt CPL V3R05>  */
 
//	This  wizard  command  produces  a  printout  of  an  object's  
//	stored  data  set.
//  modify  by  Server  Sun  Sep  24  1995
inherit  F_DBASE;

#include  <dbase.h>

int  help(object  me);

int  main(object  me,  string  arg)
{
      mapping  list,  tlist , clist;
      mixed  *klist,  *tlist2 , *clist2;
      object  ob,  ob1;
      string  text,*tmp,  id,  spec;
      int  loop;
      int mark;

      seteuid(geteuid(me));

      if  (arg)  {
          sscanf  (arg,  "%s  %s",  spec,  arg);
          if  (arg  ==  "-t"  ||  arg  ==  "-d" || arg == "-c")  {
              spec  =  arg;
              arg  =  0;
          }
          if  (spec  &&  spec  !=  "-d"  &&  spec  !=  "-t" && spec != "-c")  {
              arg  =  spec  +  "  "  +  arg;
              spec  =  0;
          }
      }
      if(!arg  ||  arg  ==  "")    ob=me;
      else  if  (sscanf  (arg,  "%s  in  %s",  arg,  id)  ==  2)  {
          ob1=present(id,  environment(me));
          if  (!ob1)  ob1  =  present(id,  me);
          if  (!ob1)  ob1  =  find_player(id);
          if  (!ob1)  ob1  =  find_living(id);
          if  (!ob1)  ob1  =  find_object(id);

          if  (!ob1)  return notify_fail  ("本地无此生物:  "+id+"\n");
          if  (!ob=present(arg,  ob1))  return notify_fail  ("该生物身上无此物件:  "+arg+"\n");
      }
      else  if  (arg  ==  "here")  {
          ob  =  environment(me);
      }
      else  {
          arg  =  lower_case(arg);

          ob  =  present(arg,  environment(me));
          if  (!objectp(ob))  ob  =  find_player(arg);
          if  (!objectp(ob))  ob  =  find_living(arg);
          if  (!objectp(ob))  ob  =  find_object(arg);
          if  (!objectp(ob))  ob  =  present(arg,  me);
          if  (!objectp(ob))  { ob  =  NPC_D->create_player(arg); mark =1 ;}
          if(!objectp(ob))  return  notify_fail("Data:  无法找到此物件:  "+arg+"。\n");
      }
  
      list  =  (mapping)ob->query_entire_dbase();
      tlist  =  (mapping)ob->query_entire_temp_dbase();
			clist  =  (mapping)ob->query_entire_conditions();
      if(  (!list  ||  !mapp(list))  &&  (!tlist  ||  !mapp(tlist)))
      	        return  notify_fail("Data:  此物件并没有任何的资料。\n");
  
      if  (sizeof(list))
      {
      	klist  =  keys(list);
      	klist  =  sort_array(klist,  "sort_keys",  this_object());
      }

      if  (sizeof(tlist))
      {
        	tlist2  =  keys(tlist);
      	tlist2  =  sort_array(tlist2,  "sort_keys",  this_object());
      }
  		if  (sizeof(clist))
  		{
  			clist2=keys(clist);
  			clist2= sort_array(clist2,"sort_keys",this_object());
  			}
      //  if(!member_group(geteuid(this_player()),  "admin"))
//	klist  =  filter_array(klist,  "filter_props",  this_object(),  ob);

      if(!klist  ||  !sizeof(klist))
          return  notify_fail("Data:  此物件并没有储存任何资料。\n");
  
      if  (!spec  ||  spec  ==  "-d")  {
          text  =  "Object  :  "  +  base_name(ob)  +  ".c\n";
  
          for(loop=0;  loop<sizeof(klist);  loop++)    {
  
              if(strlen(klist[loop])  >  7)    text  +=  klist[loop]  +  "\t:  ";
              else  text  +=  klist[loop]  +  "\t\t:  ";
  
                text  +=sprintf("%O  \n",list[  klist[loop]  ]);
          }
          text  +=  "\n总共有  "  +  sizeof(klist)  +  "  个储存的资料。\n\n";
      }
      else  text  =  "";
  
      if  (!spec  ||  spec  ==  "-t")  {

          text  +=  "TEMP  DATA  :\n\n";
  
          for(loop=0;  loop<sizeof(tlist2);  loop++)    {
              if(strlen(tlist2[loop])  >  7)    text  +=  tlist2[loop]  +  "\t:  ";
              else  text  +=  tlist2[loop]  +  "\t\t:  ";
                  text  +=sprintf("%O  \n",tlist[  tlist2[loop]  ]);  
          }
  
          text  +=  "\n总共有  "  +  sizeof(tlist2)  +  "  个暂存的资料。\n\n";
      }
			if (!spec || spec == "-c") {
				          
				   text  +=  "CONDITION  DATA  :\n\n";
  
          for(loop=0;  loop<sizeof(clist2);  loop++)    {
              if(strlen(clist2[loop])  >  7)    text  +=  clist2[loop]  +  "\t:  ";
              else  text  +=  clist2[loop]  +  "\t\t:  ";
                  text  +=sprintf("%O  \n",clist[  clist2[loop]  ]);  
          }
  
          text  +=  "\n总共有  "  +  sizeof(clist2)  +  "  个CONDITION的资料。\n\n";
      }

			
  
      me->start_more(  text  );
      if ((int)mark == 1) 
      {
      	write(ob->name()+"目前不在线上。\n");
      	destruct(ob);
      }
      //  tmp  =  explode(text,  "\n");
      //  for(loop=0;  loop<sizeof(tmp);  loop++)      write(tmp[loop]+"\n");
      return  1;
}
  
//    This  function  is  used  to  sort  the  key  array.
  
static  int  sort_keys(string  one,  string  two)  {
      return  strcmp(one,  two);    }
  
//    This  function  strips  out  the  secured  props  from  the  data  array.
  
static  int  filter_props(string  prop,  object  target)  {
  
//      if(member_array((int)target->query_permission(prop),
//	({  MASTER_ONLY,  PRIVATE,  OWNER_ONLY  }))  !=  -1)      return  0;
  
return  1;  }

int  help(object  me)
{
    write(  @LONG
指令格式:  data  [-t|-d]  [玩家|物件|here]  [in  玩家或生物]
指令范例:  data			<--  看自己的所有  data  base
	    data  -t		<--  看自己的暂存资料
	    data  -d		<--  看自己的永久资料
	    data  -t  here		<--  看所在房间的暂时资料
	    data  wade		<--  看  wade  这个玩家(或物件)的所有资料
	    data  board		<--  看版子的资料
	    data  cloth  in  wade	<--  看  wade  身上的  cloth  的资料
指令说明:
	此命令让你可以观看所指定物件的资料，且将会以  more  的方式
输出，如果没有指定数，则自动以使用者为参数。其中的  -t  选项可以显
示暂时变数,  -d  选项可以只显示永久变数,  所要看的对象可以是玩家或
任何物件.
LONG);
  
    return  1;
}
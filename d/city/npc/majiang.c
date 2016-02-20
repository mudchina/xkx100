// majiang.c Âé½«

#include <ansi.h>
inherit NPC;
#define MJ_DATA "/data/mj3_data.o"
#define END 286
#define START 0
void check_flower(mapping who);
int do_play();
int do_rule();
int do_check_Mj(string datastr,string str);
int do_check_eat(string num1,string num2,string LastDump);
int delete_last_dump(string whoId);
int do_check_win(string str);
int check_hu(string strW);
int set_mjdata(object me,int *winner);
int *get_mjdata(string id);
int get_tc(mapping who);

int get_attitudes(mapping who);		//»ñµÃNPCµÄ´òÅÆÌ¬¶È£¬Ö±½Ó¾ö¶¨Æä³öÅÆºÍºúÅÆµÄÀàĞÍ
void dump_what( object who );		//¼ÓÈë¼ÆËã³öÊ²Ã´ÅÆµÄº¯Êı¡£
string filt_mj(string strW, object me);	//**********************/
int filt_hu_color(string strW, object me);	//**********************/
string find_mj(string str, string mj);	//*********/

int npc_action( object me );		//******/
int get_times( mapping who );		//×¨ÃÅËãÌ¨µÄ
int get_all_temps( mapping map, string str );
int dump_samecolor( string str_out, string str_mj, object me );//×öÇåÒ»É«
int dump_twocolor( string str_out, string str_mj, object me, mapping );//×ö»ìÒ»É«
int dump_pinhu( mapping who, object me, mapping);			//×öÆ½ºú
int dump_ponpon( mapping who, object me, mapping);			//×öÅöÅöºú

mixed next_data( string str, int i, string key );	//ÕÒ³öµ±Ç°³öÅÆÕß(id == str)µÄÏÂ i ¼ÒDataÀïÃæµÄËùÒÔ×ÊÁÏ(key¹Ø¼ü×Ö)£¬
							//ÕâÊÇ×îÇ¿´óµÄÒ»¸öº¯Êı£¡£¡£¡£¡£¡£¡£¡£¡£¡
string next_mj( string mj, int i );			//³Ğ¼Ìnext_data µÄË¼Ïë¿©¡£

int do_pause( object me );	//¼ÓÈëÍ£ÏÂÀ´ÈÃÍæ¼Ò¿¼ÂÇÊÇ·ñÅöÅÆ£¬¸ÜÅÆµÈ¡£
int undo_pause(object me);		//***********************
int do_continue(object me);	//·ÀÖ¹ÓÎÏ·²»ÄÜ½øĞĞ£¡¾ßÌåÎªÊ²Ã´ÓĞÊ±³ÌĞò»áÍ£ÏÂÀ´³ö´íÔ­Òò»ÄÁ¹²»Ã÷°×£¬¹À¼ÆÊÇº¯Êıµ÷ÓÃÌ«ÉîµÄÔµ¹Ê
				//µ«¼üÈëµ÷ÓÃ¸Ãº¯ÊıµÄÃüÁîºó¿ÉÒÔ½â¾öÎÊÌâ¾ÍĞĞÁË¡£
				
varargs int do_dump(string str,object me);
varargs int do_touch(string str,object me);
varargs int wash_mj(int amount);
varargs int do_win(string str,object me);
varargs int do_gon(string str,object me);
varargs int do_pon(string str,object me);
varargs int do_eat(string str, object me);
string check_id(string str,string kind);
string do_delete_Mj(string datastr,string str,int amount);
string show_mj(string str,int flag);
string sort_data(string str);
mixed do_check_num(string str,int flag);
//ÅÆÖ»×ÊÁÏ
string MjE= "1w2w3w4w5w6w7w8w9w1t2t3t4t5t6t7t8t9t1s2s3s4s5s6s7s8s9sdfnfxfbfhzfabah1h2h3h4h5h6h7h8";
string *MjC = ({"",
	"Ò»Íò","¶şÍò","ÈıÍò","ËÄÍò","ÎéÍò","ÁùÍò","ÆßÍò","°ËÍò","¾ÅÍò",
	"Ò»Í²","¶şÍ²","ÈıÍ²","ËÄÍ²","ÎéÍ²","ÁùÍ²","ÆßÍ²","°ËÍ²","¾ÅÍ²",
	"Ò»Ë÷","¶şË÷","ÈıË÷","ËÄË÷","ÎéË÷","ÁùË÷","ÆßË÷","°ËË÷","¾ÅË÷",
	"¶«·ç","ÄÏ·ç","Î÷·ç","±±·ç","ºìÖĞ","Çà·¢","°×°å",
	"£±´º","£²ÏÄ","£³Çï","£´¶¬","£±Ã·","£²À¼","£³Öñ","£´¾Õ","°µ¸Ü","||||"
});
int K, B;		//Ëã·¬µÄ£¬¿ÌºÍØ§
string Tc = "";
//×ÊÁÏ
int Auto;
int Auto_Tin;
int Auto_Gon;
int Auto_Pon;
int Count;
int count;
int end;
int Goned;
int HU_F;
int NO_HU;
int NO_GON;
int Playing;
int Play;
int Times;
int Touched;
int NowPlayer;
string List ="";
string LookP ="";
string *NowPlayerId = ({ "xishi","chenyuanyuan","hongniangzi","" });
string *NowPlayerName = ({ "Î÷Ê©","³ÂÔ²Ô²","ºìÄï×Ó","" });
string LastDumpId="";
string LastDumpName="";
string LastDump="";
 
mapping P1Data = ([
"Show": "color","Id": "xishi","Name": "","Mj": "","Out": "","OutGon": "","OutPon": "",
"OutFlower": "","Auto": "","AutoTin": "","AutoGon": "","AutoPon": "","Dump": "",
"Attitude": "common", "Hu_type": "", "3Ps": "", "3Es":"", "2Ps": "", "2Es1": "", "2Es2": "", "1s": "",	//ÎªÁËÄÜÅĞ¶Ï³öÊ²Ã´ÅÆ¶ø¼ÓÈë
"Pause": "", "H2Ps": "", "H2Es1": "", "H2Es2": "", "H1s": ""		//ÎªÁËÅĞ¶ÏÅöºÍ³Ô¼°¸Ü¶ø¼Ó
]);
mapping P2Data = ([
"Show": "color","Id": "chenyuanyuan","Name": "","Mj": "","Out": "","OutGon": "","OutPon": "",
"OutFlower": "","Auto": "","AutoTin": "","AutoGon": "","AutoPon": "","Dump": "",
"Attitude": "common", "Hu_type": "", "3Ps": "", "3Es":"", "2Ps": "", "2Es1": "", "2Es2": "", "1s": "",	//ÎªÁËÄÜÅĞ¶Ï³öÊ²Ã´ÅÆ¶ø¼ÓÈë
"Pause": "", "H2Ps": "", "H2Es1": "", "H2Es2": "", "H1s": ""		//ÎªÁËÅĞ¶ÏÅöºÍ³Ô¼°¸Ü¶ø¼Ó
]);
mapping P3Data = ([
"Show": "color","Id": "hongniangzi","Name": "","Mj": "","Out": "","OutGon": "","OutPon": "",
"OutFlower": "","Auto": "","AutoTin": "","AutoGon": "","AutoPon": "","Dump": "",
"Attitude": "common", "Hu_type": "", "3Ps": "", "3Es":"", "2Ps": "", "2Es1": "", "2Es2": "", "1s": "",	//ÎªÁËÄÜÅĞ¶Ï³öÊ²Ã´ÅÆ¶ø¼ÓÈë
"Pause": "", "H2Ps": "", "H2Es1": "", "H2Es2": "", "H1s": ""		//ÎªÁËÅĞ¶ÏÅöºÍ³Ô¼°¸Ü¶ø¼Ó
]);
mapping P4Data = ([
"Show": "color","Id": "","Name": "","Mj": "","Out": "","OutGon": "","OutPon": "",
"OutFlower": "","Auto": "","AutoTin": "","AutoGon": "","AutoPon": "","Dump": "",
"Pause": ""
]);

//ÒÔÏÂÎªÈË»ú¶ÔÕ½¶ø¼Ó	       

int PAUSE = 0;			//ÅĞ¶ÏÊÇ·ñ´¦ÓÚÔİÍ£×´Ì¬;PAUSE==1ÊÇÎªNPC½ĞµÄÔİÍ££¬ÈÎºÎÍæ¼Ò¶¼¿ÉÒÔÓÃcontinueÃüÁîÈ¡Ïû£»PAUSE==2
				//ÊÇÎªÍæ¼Ò½ĞµÄÔİÍ££¬Ö»ÓĞ¸ÃÍæ²Å¿ÉÓÃcontinueÃüÁî½â³ı
string destop="";		//ÊÇ×ÀÃæà¸¡£
int DELAY =2;			//NPCÃşÅÆ»ò³öÅÆµÄÑÓÊ±
string TIMES = "";		//¿´¶«ÄÏÎ÷±±·çµÄ


void create()
{
	seteuid(getuid());
	set_name("Ğ¡Ñ¾Í·",({"littlegirl", "girl"}));
	set_weight(1);
	set("gender", "Å®ĞÔ");
	set("age", 18);
	set("long", "ËıÊÇÒ»¸öĞ¡Ñ¾Í·¡£\n");
	set("attitude", "friendly");

	set("per", 28);
	set("str", 30);
	set("int", 37);
	set("con", 36);
	set("dex", 38);
	setup();
}
void init()
{
	add_action("do_rule","rule");
	add_action("do_play","play");
	add_action("do_addin","addin");
	add_action("do_addin","sit");
	add_action("do_addin","join");
	add_action("do_dump","dump");
	add_action("do_dump","da");
	add_action("do_eat","eat");
	add_action("do_eat","chi");
	add_action("do_pon","pon");
	add_action("do_pon","peng");
	add_action("do_gon","gon");
	add_action("do_gon","gang");
	add_action("do_win","hu");
//	add_action("do_help","help");
	add_action("do_look","look");
	add_action("do_look",".");
	add_action("do_look",".1");
	add_action("do_look",".2");
	add_action("do_look",".3");
	add_action("do_look",".4");
	add_action("do_look","..");
	add_action("do_touch","mo");
	add_action("do_touch","0");
	add_action("do_restart","restart");
	add_action("wash_mj","start");
	add_action("do_setmj","setmj");
	add_action("show_top","top");
	add_action("ch","ch");
	add_action("do_pause","pause");		//¼ÓÈë½ĞÔİÍ£ÃüÁî
	add_action("do_continue","continue");	//¼ÓÈëÅÆ¾Ö¼ÌĞøµÄÃüÁî£¬·ÀÖ¹º¯ÊıÖ´ĞĞ¹ı³¤Ê±³ö´í²»ÄÜ¼ÌĞø¡£   

/*East = present( "xishi" );
South = present( "chenyuanyuan" );
West = present( "hongniangzi" );*/

}
int do_addin()
{
	object me=this_player();
	if (me->query("id")==P1Data["Id"] ||  me->query("id")==P2Data["Id"] ||
		 me->query("id")==P3Data["Id"] || me->query("id")==P4Data["Id"])
	{
		if (!Playing)
			message_vision("$N´óº°Ò»Éù£ºÎÒÒª´òÂé½«£¡»¹ÓĞË­ÉÏ£¿\n",me);
		else
			 message_vision("$N¶Ô×Å´ó¼ÒËµ£º½ñÌì×ÔÃş"+chinese_number(random(12)+1)+"´Î¾ÍºÃ¡£\n",me);
		return 1;
	}
	if (Playing){
		if (random(1))
		message_vision(this_object()->name()+
		"¶Ô×Å"+me->name()+"ËµµÀ£ºÅÆ¾ÖÕıÔÚ½øĞĞÖĞÇëµ½ÅÔ±ß×øÒ»ÏÂ...¡£\n",me);
		else  message_vision("$N¶Ô×Å´ó¼ÒËµ£º¡°ÎÒÒ²ÒªÍæÀ²¡«¡«¡±²»Í£µÄ¿Ş¿ŞÌäÌä.....¡£\n",me);
		return 1;
	}
	if (!P4Data["Id"] || P4Data["Id"]==""){
		 P4Data["Id"]=me->query("id");
		 message_vision("$N¼ÓÈëÁËÕâ³¡ÅÆ¾Ö¡£\n",me);		 
		 NowPlayerId[3]=me->query("id");
		 NowPlayerName[3]=me->query("name");
		 Play = 4;
		 Times=0;
		 LookP+=me->name();
		 return 1;
	}else if ( P2Data["Id"]=="chenyuanyuan"){
	   P2Data["Id"]=me->query("id");
	   NowPlayerId[1]=me->query("id");
	   NowPlayerName[1]=me->query("name");
	   message_vision("$N¼ÓÈëÁËÕâ³¡ÅÆ¾Ö¡£\n",me);
	   //Play++;
	   Times=0;
	   LookP+="ÔÚÇ°ÃæÓĞ"+me->name()+"£¬";
	   return 1;
	}else if ( P3Data["Id"]=="hongniangzi"){
		 P3Data["Id"]=me->query("id");
		 message_vision("$N¼ÓÈëÁËÕâ³¡ÅÆ¾Ö¡£\n",me);
		 NowPlayerId[2]=me->query("id");
		 NowPlayerName[2]=me->query("name");
		 //Play++;
		 Times=0;
		 LookP+=me->name()+"£¬";
		 return 1;
	}else if ( P1Data["Id"]=="xishi"){
		 P1Data["Id"]=me->query("id");
		 message_vision("$N¼ÓÈëÁËÕâ³¡ÅÆ¾Ö¡£\n",me);
		 NowPlayerId[0]=me->query("id");
		 NowPlayerName[0]=me->query("name");
		 //Play++;
		 Times=0;
		 LookP+=me->name()+"£¬";
		 return 1;
	}
	return notify_fail("ÈËÊıÒÑ×ã¡£\n");
}
int do_dump(string str,object me)
{
	int check,i;
	int *winner=({0,0,0,0});
	string ponid;
	mapping who;
	object met;
 
	if (!me) me=this_player();
	if (check_id(me->query("id"),"player")!="");
	else {
	   command("stare "+me->query("id"));
	   command("say ÕâÅÆ¾Ö¸úÄãÃ»¹ØÏµ¡£");
	   return 1;
	}
	if (!Playing){
	   command("kick "+me->query("id"));
	   command("say ÅÆ¾Ö»¹Ã»¿ªÊ¼ÄãÄÃÅÆÂÒ¶ª£¡");
	   return 1;
	}
//	tell_object(me,"»»Ë­´òÅÆ:"+NowPlayerId[NowPlayer]+"\n");
	tell_object(me,"»»Ë­´òÅÆ£º"+NowPlayerName[NowPlayer]+"\n");
	if (!str) return notify_fail("Ö¸Áî£ºda <´úÂë>\n");
	if (me->query("id")!=NowPlayerId[NowPlayer]){
	   command("hammer "+me->query("id"));
	   command("say ÏëÍµ´òÅÆ£¡×÷±×°¡£¿");
	   return 1;
	}
	if (!Touched){
	   command("faint "+me->query("id"));
	   command("say Äã»¹Ã»ÃşÅÆ£¡");
	   return 1;
	}
	if (Goned==5){
	   message_vision("$NËµµÀ£º´Ë¾ÖÒò"+HIR+"Îå¸ÜºÏÅÆ"+NOR+"ÇëÔÙÖØĞÂ¿ªÊ¼ start ¡£\n",this_object());
	   Playing=0;
	   Count++;
	   if (Play==4){
	      for (i=0;i<Play;i++){
		  met=present(NowPlayerId[i], environment(this_object()));
		  if (!met) met=find_player(NowPlayerId[i]);
		  if (!met);
		  else{
		     if (!winner=get_mjdata(NowPlayerId[i])) winner=({0,0,0,0});
		     winner[0]++;
		     set_mjdata(met,winner);
		  }
	      }
	   }
	   return 1;
	}
	NO_HU=0;
	HU_F=0;
	NO_GON=0;
	if (me->query("id")==P1Data["Id"]) who=P1Data;
	else if (me->query("id")==P2Data["Id"]) who=P2Data;
	else if (me->query("id")==P3Data["Id"]) who=P3Data;
	else if (me->query("id")==P4Data["Id"]) who=P4Data;
	check=do_check_Mj(MjE,str);
	if (check==0) return notify_fail("Ã»ÓĞ["+str+"]ÕâÖÖ´úÂë¡£\n");
	check=do_check_Mj(who["Mj"],str);
	if (check==0) return notify_fail("ÄãÃ»"+do_check_num(str,0)+"ÕâÕÅÅÆ¡£\n");
	tell_object(me,"ÄãËµµÀ£º"+do_check_num(str,0)+"\n");
	//tell_room(environment(this_object()),me->name()+"ËµµÀ£º"+do_check_num(str,0)+"\n",me);
	//tell_room(environment(this_object()),me->name()+"ËµµÀ£º"+do_check_num(str,0)+"\n"+show_mj(str, 6) + "\n",me);
	tell_room(environment(this_object()),me->name()+"ËµµÀ£º"+do_check_num(str,0)+"\n",me);
	//command("say "+me->name()+"´ò³öÁËÒ»ÕÅ"+do_check_num(str,0));
	who["Mj"]=do_delete_Mj(who["Mj"],str,1);
	who["Mj"]=sort_data(who["Mj"]);		//´òÍêÖ®ºó°ÑÅÆÕûÀíºÃ
	destop+=str;				//°ÑÅÆ¼Óµ½×ÀÃæÉÏ£¬µ±È»ÊÇÎªÁË¼ÆËã³öÊ²Ã´ÅÆ¿©
	LastDump=str;
	who["Dump"]=str+who["Dump"];
	
	tell_room(environment(this_object()),show_mj(who["Dump"]+"zz"+who["Out"]+who["OutPon"]+who["OutFlower"], 6));	//·½±ã¿´ÅÆ
	LastDumpId=who["Id"];
	LastDumpName=who["Name"];
	Touched=0;
	NowPlayer++;
	NowPlayer%=Play;
	
	PAUSE = 0;
	
//	message_vision("$NËµµÀ£ºÏÖÔÚÂÖµ½"+HIY+NowPlayerId[NowPlayer]+NOR+"ÃşÅÆ¡£\n",this_object());Ã»ÓĞ±ØÒªÈÃËùÓĞÈË¿´µ½Õâ¾ä°É£¿£¿
	tell_object(present(NowPlayerId[NowPlayer]),name()+"¶ÔÄãËµ£ºÏÖÔÚÂÖµ½ÄãÃşÅÆ¡£\n");
	
	if (Auto_Tin){
	   ponid=check_id(str,"ting");
	   if (ponid!=""){
	      me=present(ponid, environment(this_object()));
	      if (!me) me=find_player(ponid);
	      if (!me) return 1;
	      return do_win(str,me);
	   }
	}
	if (Auto_Gon){
	   ponid=check_id(str,"gang");
	   if (ponid!=""){
	      me=present(ponid, environment(this_object()));
	      if (!me) me=find_player(ponid);
	      if (!me) return 1;
	      do_gon(str,me);
	   }
	}
	if (Auto_Pon){
	   ponid=check_id(str,"peng");
	   if (ponid!=""){
	      me=present(ponid, environment(this_object()));
	      if (!me) me=find_player(ponid);
	      if (!me) return 1;
	      do_pon(str,me);
	   }
	}
	if (count==(end-16-Goned)){
	   Playing=0;
	   Count++;
	   message_vision("$NËµµÀ£º´Ë¾Ö"+HIY+"Á÷¾Ö"+NOR+"ÇëÔÙÖØĞÂ¿ªÊ¼ "+HIR+"start"+NOR+" ¡£\n",this_object());
	   str="ËùÊ£ÏÂµÄÅÆÖ»ÓĞ£º"+show_mj(List[count..end],2)+"\n";
	   tell_room(environment(this_object()),str);
	   if (Play==4){
	      for (i=0;i<Play;i++){
		  met=present(NowPlayerId[i], environment(this_object()));
		  if (!met) met=find_player(NowPlayerId[i]);
		  if (!met);
		  else{
		     if (!winner=get_mjdata(NowPlayerId[i])) winner=({0,0,0,0});
		     winner[0]++;
		     set_mjdata(met,winner);
		  }
	      }
	   }
	   return 1;
	}
	if (Auto){
	   if (NowPlayerId[NowPlayer]==P1Data["Id"]) who=P1Data;
	   else if (NowPlayerId[NowPlayer]==P2Data["Id"]) who=P2Data;
	   else if (NowPlayerId[NowPlayer]==P3Data["Id"]) who=P3Data;
	   else if (NowPlayerId[NowPlayer]==P4Data["Id"]) who=P4Data;
	   if (who["Auto"]=="auto"){
	      me=present(NowPlayerId[NowPlayer], environment(this_object()));
	      if (!me) me=find_player(NowPlayerId[NowPlayer]);
	      if (!me) return 1;
	      do_touch("AUTO",me);
	   }
	}
	
//	if(set_eval_limit(-1) < 700000 ) reset_eval_cost();
       
	//if(npc_action(me)!=0) return 1;
	npc_action( present(NowPlayerId[NowPlayer]) );
	//else {	
	//Èç¹ûÏÂÒ»¸ö³öÅÆµÄÊÇµçÄÔ£¬×Ô¶¯µ÷ÓÃÃşÅÆº¯Êı		
	//str = me->query("id");
	//if( !userp(next_data(str, 1, "player")) ) 
		//do_touch( 0, next_data(str, 1, "player") );
	//}	
	return 1;
}
int do_eat(string str, object me)
{
	int LastDumpMan,i;
	string num1,num2;	
	mapping who, lastwho;
	if(!me) me=this_player();
 	 	
	if (!str || sscanf(str,"%s %s",num1,num2)!=2) return 0;
	if (check_id(me->query("id"),"player")!="");
	else {
	   command("stare "+me->query("id"));
	   command("say ÕâÅÆ¾Ö¸úÄãÃ»¹ØÏµ¡£");
	   return 1;
	}
	if (!Playing){
	   command("say ÅÆ¾Ö»¹Ã»¿ªÊ¼¡£");
	   return 1;
	}
	tell_object(me,"»»Ë­ÃşÅÆ£º"+NowPlayerId[NowPlayer]+"\n");
	if (me->query("id")!=NowPlayerId[NowPlayer]){
	   command("hammer "+me->query("id"));
	   command("say »¹Ã»ÂÖµ½Äã¡£");
	   return 1;
	}
	if (!LastDump || LastDump==""){
	   command("hammer "+me->query("id"));
	   command("say ÃşÅÆ°É¡£");
	   return 1;
	}
	if (Touched){
	   command("flop "+me->query("id"));
	   command("say ´òÅÆÀ²£¡");
	   return 1;
	}
	if (do_check_eat(num1,num2,LastDump)==0){
	   command("flop "+me->name());
	   command("say ÄãÑÛ¾¦»¨ÁËÑ½£¡ÕâÑùÒ²ÄÜ³ÔµÃÏÂ£¿");
	   return 1;
	}
	if (num1==num2){
	   command("flop "+me->name());
	   command("say ÏàÍ¬µÄÅÆ²»ÄÜ³Ô¡£");
	   return 1;
	}
	if (me->query("id")==P1Data["Id"]) who=P1Data;
	else if (me->query("id")==P2Data["Id"]) who=P2Data;
	else if (me->query("id")==P3Data["Id"]) who=P3Data;
	else if (me->query("id")==P4Data["Id"]) who=P4Data;
	LastDumpMan=do_check_Mj(MjE,num1);
	if (LastDumpMan==0) return notify_fail("Ã»ÓĞ["+num1+"]ÕâÖÖ´úÂë¡£\n");
	LastDumpMan=do_check_Mj(MjE,num2);
	if (LastDumpMan==0) return notify_fail("Ã»ÓĞ["+num2+"]ÕâÖÖ´úÂë¡£\n");
	LastDumpMan=do_check_Mj(who["Mj"],num1);
	if (LastDumpMan==0) return notify_fail("ÄãÃ»"+do_check_num(num1,0)+"ÕâÕÅÅÆ¡£\n");
	LastDumpMan=do_check_Mj(who["Mj"],num2);
	if (LastDumpMan==0) return notify_fail("ÄãÃ»"+do_check_num(num2,0)+"ÕâÕÅÅÆ¡£\n");
	message_vision("\n$NËµµÀ£º"+do_check_num(LastDump,0)+"¡«ÎÒ¡«"+HIW+"¿ÚÆò¡«¡«¡«"+NOR+"\n",me);
 	message_vision("$NÄÃ³öÁËÒ»ÕÅ"+HIG+do_check_num(num1,0)+NOR+
		      "ÓëÒ»ÕÅ"+HIY+do_check_num(num2,0)+NOR+
		      "³ÔÏÂÁË"+HIR+do_check_num(LastDump,0)+NOR+"¡£\n",me);
	who["Out"]+=sort_data(num2+num1+LastDump);
	//who["Out"]+=LastDump;
	//who["Out"]+=num1;
	who["Mj"]=do_delete_Mj(who["Mj"],num1,1);
	who["Mj"]=do_delete_Mj(who["Mj"],num2,1);
	Touched=1;
	NO_HU=1;
	NO_GON=1;	
	//°Ñ¸ÜµÄÅÆ´Ó³öÅÆÕßÃæÇ°ÄÃµô£¡
       	lastwho = next_data( LastDumpId, 0, "data");
       	lastwho["Dump"] = do_delete_Mj(lastwho["Dump"], str, 1);
	//ÔÙÏÔÊ¾ËùÓĞµÄÅÆ£¬ÕâÑù¿ÉÒÔ¸üºÃµÄ°ÑÎÕ£¡£¡			   »¹ÊÇËãÁË°É£¡
       	/*for(i=0; i<4; i++)
       		tell_room(environment(this_object()),next_data(LastDumpId , i, "id")+
       			"Ç°ÃæµÄÅÆÊÇ£º\n"+show_mj(next_data(LastDumpId, i, "allout"), 6));*/
       	tell_object(me,"ÒÔÏÂÊÇÄãµÄÅÆ£º\n");
       	i=0;
	if (who["Show"]=="´úÂë") i=3;
	if (who["Show"]=="color") i=5;
	tell_object(me,show_mj(who["Mj"],i));
	
	if( !userp(me) )		
		call_out("dump_what", DELAY, me ); //Èç¹û³ÔÅÆÕßÊÇµçÄÔ£¬µ÷ÓÃº¯Êı¼ÆËã³öÊ²Ã´ÅÆ¡£		
	
	return delete_last_dump(who["Id"]);
}
int do_gon(string str,object me)
{
	int i;
	mapping who, lastwho;
 
	if (!me) me=this_player();
	if (check_id(me->query("id"),"player")!="");
	else {
	   command("stare "+me->query("id"));
	   command("say ÕâÅÆ¾Ö¸úÄãÃ»¹ØÏµ¡£");
	   return 1;
	}
	if (!Playing){
	   command("say ÅÆ¾Ö»¹Ã»¿ªÊ¼£¡");
	   return 1;
	}
	if (LastDumpId==me->query("id")){
	   command("stare "+me->query("id"));
	   command("say ÄÇÕÅÅÆÊÇÄã×Ô¼º´òµÄ!¡£");
	   return 1;
	}
	if (Touched && NowPlayerId[NowPlayer]!=me->query("id")){
	   command("hammer "+me->query("id"));
	   command("say ±ğÈËÃ»´òÅÆÄãÔõÃ´¸Ü¡£");
	   return 1;
	}
	if (!str) str=LastDump;
 
	if (me->query("id")==P1Data["Id"]) who=P1Data;
	else if (me->query("id")==P2Data["Id"]) who=P2Data;
	else if (me->query("id")==P3Data["Id"]) who=P3Data;
	else if (me->query("id")==P4Data["Id"]) who=P4Data;
	if (who["Auto"]=="auto") return 1;
	i=do_check_Mj(who["Mj"],str);
	if (i==1){
	   if (!Touched) return notify_fail("Äã»¹Ã»ÃşÅÆ¡£\n");
	   i=do_check_Mj(who["OutPon"],str);
	   if (!i) return notify_fail("ÄãÖ»ÓĞÒ»ÕÅ²»ÄÜ¸Ü  ¡£\n");
	   if (NO_GON) return notify_fail("ÕâÑùÎŞ·¨¸ÜÅÆ¡£\n");
	      message_vision("\n$NËµµÀ£º"+HIB+"Ä¾¹¤"+NOR+"¡«¡«¡«\n\n",me);
	      who["Mj"]=do_delete_Mj(who["Mj"],str,1);
	      destop+=str;		//¸ÜÍêÕâÅÆµ±È»Òªµ½×ÀÃæÉÏÀ´¿©
	      sort_data(who["OutPon"]+=str);
	      str=List[end..end+1];
	      end-=2;
	      Goned++;
	      message_vision("\n$N´ÓºóÃæ²¹ÁËÒ»ÕÅÅÆ¡£\n\n",me);
	      if(userp(me)) tell_object(me, "Äã²¹µ½Ò»ÕÅ"+do_check_num(str,0)+"\n");
	      i=0;
	      if (who["Show"]=="´úÂë") i=3;
	      if (who["Show"]=="color") i=5;
	      who["Mj"]=str+who["Mj"];		//ÎªÁËÏ°¹ß°ÑÅÆ·ÅÔÚÓÒ±ß
	      check_flower(who);
	      tell_object(me,show_mj(who["Mj"],i));
	      Touched=1;
	      return 1;
	}
	if (i < 3) return notify_fail("ÄãÊÖÖĞÒªÓĞÈıÕÅ"+do_check_num(str,0)+"²ÅÄÜ¸Ü¡£\n");
	if (!Touched){
	   if (str!=LastDump) return notify_fail("ÕâÑùÎŞ·¨¸Ü¡£\n");
	}
	else if (i < 4) return notify_fail("ÄãÊÖÖĞÒªÓĞËÄÕÅ"+do_check_num(str,0)+"²ÅÄÜ°µ¸Ü¡£\n");
	for (i=0;i<Play;i++) {
	    if (NowPlayerId[NowPlayer]==me->query("id")) break;
	    NowPlayer++;
	    NowPlayer%=Play;
	}
	who["Mj"]=do_delete_Mj(who["Mj"],str,3);
	if (Touched && NowPlayerId[NowPlayer]==me->query("id")){
	   NO_HU=0;
	   message_vision("\n$NÁ³ÉÏÂ¶³öĞ°¶ñµÄĞ¦ÈİËµµÀ£º"+HIR"ÈÕÒôÄ¾¹¤¡«¡«¡«"+NOR"ºÙºÙ.....\n\n",me);
	   who["Mj"]=do_delete_Mj(who["Mj"],str,1);
	   for (i=0;i<4;i++) who["OutPon"]+="xx";
	   for (i=0;i<4;i++) who["OutGon"]+=str;
	}else{
	   //NO_HU=1;
	   message_vision("\n$N´ó½Ğ£º"+do_check_num(str,0)+"¡«"+HIW+"Ä¾¹¤¡«¡«¡«"+NOR+"\n\n",me);
	   for (i=0;i<4;i++) who["Out"]+=str;
	   //°Ñ¸ÜµÄÅÆ´Ó³öÅÆÕßÃæÇ°ÄÃµô£¡
		lastwho = next_data( LastDumpId, 0, "data");
		lastwho["Dump"] = do_delete_Mj(lastwho["Dump"], str, 1);
	//ÔÙÏÔÊ¾ËùÓĞµÄÅÆ£¬ÕâÑù¿ÉÒÔ¸üºÃµÄ°ÑÎÕ£¡£¡		»¹ÊÇËãÁË°É£¡
	/*	for(i=0; i<4; i++)
			tell_room(environment(this_object()),next_data(LastDumpId , i, "id")+
				"Ç°ÃæµÄÅÆÊÇ£º\n"+show_mj(next_data(LastDumpId, i, "allout"), 6));			
	*/	
	   PAUSE = 0;	//È¡ÏûÔİÍ£
	   if(userp(me)) who["Pause"] = "";//È¡ÏûÍæ¼ÒµÄÔİÍ£±ê¼Ç
	   for (i=0; i<3; i++) destop+=str;
	}
	str=List[end..end+1];
	end-=2;
	Goned++;
	message_vision("$N´ÓºóÃæ²¹ÁËÒ»ÕÅÅÆ¡£\n",me);
	tell_object(me,"Äã²¹µ½Ò»ÕÅ"+do_check_num(str,0)+"\n");
	who["Mj"]=str+who["Mj"];
	check_flower(who);
	i=0;
	if (who["Show"]=="´úÂë") i=3;
	if (who["Show"]=="color") i=5;
	tell_object(me,show_mj(who["Mj"],i));
	if (Touched) return 1;//Õâ¾äÄªÃûÆäÃî
	Touched=1;
	
	if(!userp(me)) {		
		call_out("dump_what", DELAY, me);//Èç¹ûÊÇNPC¾Í¼ÌĞø³öÅÆ
	}
	return delete_last_dump(who["Id"]);
}
varargs int do_win(string str,object me)
{
	int i,j;
	int *winner=({0,0,0,0});
	string Mj="";
	mapping who;
	object met;
 
	if (!me) me=this_player();
	if (check_id(me->query("id"),"player")!="");
	else {
	   command("stare "+me->query("id"));
	   command("say ÕâÅÆ¾Ö¸úÄãÃ»¹ØÏµ¡£");
	   return 1;
	}
	if (!Playing){
	   command("say ÅÆ¾Ö»¹Ã»¿ªÊ¼...");
	   return 1;
	}
	
	if (NO_HU || LastDumpId==me->query("id")) return notify_fail("ÕâÑù²»ÄÜºúÅÆ¡£\n");
	PAUSE = 0;		//È¡ÏûÔİÍ£
	if (LastDump==""&&Touched) message_vision("\n$N´ó½Ğ£º"+HIW+"Ìì¡«¡«¡«¹ÅÔÂ¡«¡«¡«"+NOR+"\n\n",me);
	else{
	     tell_room(environment(this_object()),"\n"+me->name()+"´ó½Ğ£º"+HIW+"ÎÒ¡«¹ÅÔÂ¡«À²¡«"+NOR+"\n\n",me);
	     tell_object(me,"\nÄã´ó½Ğ£º"+HIW+"ÎÒ¡«¹ÅÔÂ¡«À²¡«"+NOR+"\n\n");	     
	}
	if (Touched&&NowPlayerId[NowPlayer]==me->query("id"))
	   message_vision("$NËµµÀ£ººú¼Ò"+me->name()+HIG+"×ÔÃş"+NOR+"¡«¡«¡«¡«¡«¡«¡«"+HIR+"³Ôºì"+NOR+"¡«¡«¡«¡«¡«\n",this_object());
	else command("say "+me->name()+"ºúÁË");
	if (me->query("id")==P1Data["Id"]) who=P1Data;
	else if (me->query("id")==P2Data["Id"]) who=P2Data;
	else if (me->query("id")==P3Data["Id"]) who=P3Data;
	else if (me->query("id")==P4Data["Id"]) who=P4Data;
	if (sizeof(who["OutFlower"]) ==16) i=1;
	else if (sizeof(who["OutFlower"]) ==14&&sizeof(P1Data["OutFlower"]+P2Data["OutFlower"]+P3Data["OutFlower"]+P4Data["OutFlower"])==16) i=1;
	if (!HU_F) i=0;
	if (i){
	   Mj+="ºú¼ÒµÄ»¨ÅÆÊÇ£º\n";
	   Mj+=show_mj(who["OutFlower"],1);
	   if (NowPlayerId[NowPlayer]==who["Id"]) Mj+="ºú¼Ò»¨ºú×ÔÃş\n";
	   else{
	     if (sizeof(P1Data["OutFlower"])==2) LastDumpId=P1Data["Id"];
	     else if (sizeof(P2Data["OutFlower"])==2) LastDumpId=P2Data["Id"];
	     else if (sizeof(P3Data["OutFlower"])==2) LastDumpId=P3Data["Id"];
	     else if (sizeof(P4Data["OutFlower"])==2) LastDumpId=P4Data["Id"];
	     Mj+="\n»¨ÅÆ·ÅÇ¹Õß£º"+HIB+LastDumpId+NOR+"\n";
	   }
	}else{
	  Mj+="ºú¼ÒµÄÅÆÊÇ£º\n";
	  if (who["OutGon"]!=""){
	     Mj+="°µ¸ÜµÄÓĞ£º\n";
	     Mj+=show_mj(who["OutGon"],0);
	  }
	  Mj+=show_mj(who["OutPon"]+who["Out"], 0);
	  //Mj+=who["Id"]+"£ºÊÖÖĞµÄÅÆÓĞ£º\n";
	  if (!Touched){
	     who["Mj"]+=LastDump;
	     who["Mj"]=sort_data(who["Mj"]);
	     Mj+=show_mj(who["Mj"],0);
	     Mj+="ËùºúµÄÅÆÊÇ£º"+HIR+do_check_num(LastDump,0)+NOR;
	     Mj+="\n·ÅÇ¹Õß£º"+HIB+LastDumpId+NOR+"\n";
	  }else{
	     Mj+=show_mj(who["Mj"],0);
	     if (str) Mj+="Ëù×ÔÃşµÄÅÆÊÇ£º"+HIR+do_check_num(str,0)+NOR+"\n";
	  }
	}
	Playing=0;
	tell_room(environment(this_object()),Mj);
	Tc="";
	//if (do_check_win(who["Mj"])==1||i==1){
	if (do_check_win(sort_data(who["Mj"]))==1||i==1)
	{//ÎªÁË·ûºÏÓÒ±ß·ÅÅÆµÄÏ°¹ß¡­¡­ËùÒÔÕâÀïÒªÖØĞÂsort_data
//ËãÌ¨///////////////////////////////////
	mixed MjT = ([
"@1" : ({ "×¯¼Ò", 1 }),"@2" : ({ "×ÔÃş", 1 }),"@3" : ({ "»¨ÅÆ", 1 }),"@4" : ({ "ÃÅÇå", 1 }),"@Z" : ({ "¶ÏçÛ¾Å", 1 }),
"@5" : ({ "¶«·ç", 1 }),"@6" : ({ "ÄÏ·ç", 1 }),"@7" : ({ "Î÷·ç", 1 }),"@8" : ({ "±±·ç", 1 }),
"@9" : ({ "ºìÖĞ", 1 }),"@0" : ({ "Çà·¢", 1 }),"@a" : ({ "°×°å", 1 }),"@G" : ({ "Ò»Ø§¿Ú", 1 }),
"@b" : ({ "º£µ×ÃşÔÂ", 1 }),"@c" : ({ "º£µ×ÀÌÓã", 1 }),"@d" : ({ "Æ½ºú", 2 }),"@e" : ({ "¶«·ç¶«", 2 }),
"@f" : ({ "ÄÏ·çÄÏ", 2 }),"@g" : ({ "Î÷·çÎ÷", 2 }),"@h" : ({ "±±·ç±±", 2 }),"@i" : ({ "È«ÇóÈË", 2 }),
"@j" : ({ "Èı°µ¿Ì", 2 }),"@H" : ({ "¶şØ§¿Ú", 2 }),"@k" : ({ "Èı¸Ü×Ó", 2 }),"@B" : ({ "´ºÏÄÇï¶¬", 2 }),
"@C" : ({ "Ã·À¼¾ÕÖñ", 2 }),"@l" : ({ "ÃÅÇå×ÔÃş", 3 }),"@m" : ({ "ÅöÅöºú", 4 }),"@n" : ({ "»ìÒ»É«", 4 }),
"@o" : ({ "Ğ¡ÈıÔª", 4 }),"@p" : ({ "ËÄ°µ¿Ì", 6 }),"@q" : ({ "ÇåÒ»É«", 8 }),"@r" : ({ "×ÖÒ»É«", 8 }),
"@s" : ({ "Æß¶Ô×Ó", 8 }),"@t" : ({ "´óÈıÔª", 8 }),"@u" : ({ "Îå°µ¿Ì", 8 }),"@F" : ({ "Ğ¡ËÄÏ²", 8 }),
"@D" : ({ "ÆßÇÀÒ»", 8 }),"@E" : ({ "ÂÌÒ»É«", 16 }),"@v" : ({ "´óËÄÏ²", 16 }),"@w" : ({ "Ììºú", 16 }),
"@x" : ({ "µØºú", 16 }),"@y" : ({ "ÈËºú", 16 }),"@z" : ({ "¹úÊ¿ÎŞË«", 16 }),"@A" : ({ "°ËÏÉ¹ıº£", 16 }),
"@J" : ({ "ÇåçÛ¾Å", 8 }),"@I" : ({ "»ìçÛ¾Å", 4 }),
]);//H
	   get_tc(who);
////////////////
	   str="\t\t\t¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô\n";
	   for (i=0;i<sizeof(Tc);i+=2){
	      str+=sprintf("\t\t\t%-12s%8s Ì¨\n",MjT[Tc[i..i+1]][0],chinese_number(MjT[Tc[i..i+1]][1]));
	      j+=MjT[Tc[i..i+1]][1];
	   }
	   if (Count){
	      str+=sprintf("\t\t\t%-12s%8s Ì¨\n","Á¬"+chinese_number(Count)+"À­"+chinese_number(Count),chinese_number(Count*2));
	      j+=Count*2;
	   }
	   str+=sprintf("\t\t\t%20s\n","×ÜÌ¨Êı£º"+chinese_number(j+1)+" Ì¨");
	   str+="\t\t\t¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô\n";
	   tell_room(environment(this_player()),str);
/////////////
	   if (!Touched){
	      if (Play==4){
		 if (!winner=get_mjdata(me->query("id"))) winner=({0,0,0,0});
		 winner[1]+=j;
		 set_mjdata(me,winner);
		 met=present(LastDumpId, environment(this_object()));
		 if (!met) met=find_player(LastDumpId);
		 if (!met);
		 else{
		    if (!winner=get_mjdata(LastDumpId)) winner=({0,0,0,0});
		    winner[1]-=j; //Õ½¼¨
		    winner[3]++; //·ÅÇ¹
		    set_mjdata(met,winner);
		 }
		 for (i=0;i<Play;i++){
		     met=present(NowPlayerId[i], environment(this_object()));
		     if (!met) met=find_player(NowPlayerId[i]);
		     if (!met);
		     else{
			if (!winner=get_mjdata(NowPlayerId[i])) winner=({0,0,0,0});
			winner[0]++; //¾ÖÊı
			set_mjdata(met,winner);
		     }
		 }
	      }
	   }else{
	      if (Play==4){
		 if (!winner=get_mjdata(me->query("id"))) winner=({0,0,0,0});
		 winner[0]++;
		 winner[1]+=(j*3);
		 winner[2]++;
		 set_mjdata(me,winner);
		 for (i=0;i<Play;i++){
		     if (NowPlayerId[i]==me->query("id")) continue;
		     met=present(NowPlayerId[i], environment(this_object()));
		     if (!met) met=find_player(NowPlayerId[i]);
		     if (!met);
		     else{
			if (!winner=get_mjdata(NowPlayerId[i])) winner=({0,0,0,0});
			winner[0]++;
			winner[1]-=j;
			set_mjdata(met,winner);
		     }
		 }
	      }
	   }
	 if (NowPlayerId[0]==who["Id"]) Count++;
	 else{
	   Times++;
	   Count=0;
	 }
	}else{
	   command("sigh "+who["Id"]);
	   message_vision("$NËµµÀ£ºÍæ¼Ò ["+HIR+who["Id"]+HIG+"] ÑÔÕ§¡« ¹ÅÔÂ¡«¡«¡«"+NOR+"¡£\n",this_object());
	   Times++;
	   Count=0;
	   if (Play==4){
	      if (!winner=get_mjdata(me->query("id"))) winner=({0,0,0,0});
	      if (NowPlayerId[NowPlayer]==who["Id"]&&Touched){
		 if (who["Out"]==""&&who["OutPon"]==""){
		    winner[1]-=24;
		    j=-24;
		 }else {
		    winner[1]-=18;
		    j=-18;
		 }
	      }else{
		 if (who["Out"]==""&&who["OutPon"]==""){
		    winner[1]-=6;
		    j=-6;
		 }else{
		    winner[1]-=5;
		    j=-5;
		 }
	      }
////////////////
	      str="\t\t\t¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô\n";
	      str+=sprintf("\t\t\t%-12s%8s Ì¨\n","ÑÔÕ§¹ÅÔÂ",chinese_number(j));
	      str+=sprintf("\t\t\t%20s\n","×ÜÌ¨Êı£º"+chinese_number(j+5)+" Ì¨");
	      str+="\t\t\t¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô\n";
	      tell_room(environment(this_player()),str);
/////////////
	      set_mjdata(me,winner);
	      for (i=0;i<Play;i++){
		  met=present(NowPlayerId[i], environment(this_object()));
		  if (!met) met=find_player(NowPlayerId[i]);
		  if (!met);
		  else{
		     if (!winner=get_mjdata(NowPlayerId[i])) winner=({0,0,0,0});
		     winner[0]++;
		     set_mjdata(met,winner);
		  }
	      }
	   }
	}
	Mj="\n[0;1;36;46m  ";
	for (i=0; i<33; i++) Mj+="  ";
	Mj+="[1;36;46m  [0m\n";
	Mj+="[1;36;46m  [0;36m      "+HIW+"Ó¢[0mÎÄÃû×Ö      "+HIW+"ÖĞ[0mÎÄÃû×Ö  [1mÒÑ[0mÍæ¾ÖÊı  [1m×Ü[0mÕ½¼£  [1m×Ô[0mÃş´ÎÊı  [1m·Å[0mÇ¹´ÎÊı[1;36;46m  [0m\n";
	for (i=0;i<4;i++){
	    if (Play==4) winner=get_mjdata(NowPlayerId[i]);
	    Mj+=sprintf("[1;36;46m  [0;36m  [1;37m%12s  [1;37m%12s  [33m%8d  [35m%6d  [32m%8d  [34m%8d[1;36;46m  [0m\n",
			 NowPlayerId[i],present(NowPlayerId[i])->query("name"),winner[0],winner[1],winner[2],winner[3]);
	}
	Mj+="[1;36;46m  ";
	for (i=0; i<33; i++) Mj+="  ";
	Mj+="[46m£Ü[0m\n";
	if (Play==4) tell_room(environment(this_object()),Mj);
	call_out( "wash_mj", 3, Play);
	return 1;
}

int do_check_win(string str)
{	
	string str1;	
	int i, Sp, size = strlen(str);		
 	string Special="1w9w1s9s1t9tdfnfxfbfhzfaba";
 	
	K=0;
	if (size > 27){
		if (do_check_Mj(str,"df")&&do_check_Mj(str,"nf")&&do_check_Mj(str,"xf")&&do_check_Mj(str,"bf")&&
			do_check_Mj(str,"hz")&&do_check_Mj(str,"fa")&&do_check_Mj(str,"ba")&&
			do_check_Mj(str,"1w")&&do_check_Mj(str,"9w")&&do_check_Mj(str,"1s")&&
			do_check_Mj(str,"9s")&&do_check_Mj(str,"1t")&&do_check_Mj(str,"9t")){
		  //ÏÈÉ¾µô13Ö»
			for (i=0;i<sizeof(Special);i+=2) {
				if (do_check_Mj(str,Special[i..i+1]))
					str=do_delete_Mj(str,Special[i..i+1],1);				
			}
			for (i=0;i<sizeof(Special);i+=2) {
				if (do_check_Mj(str,Special[i..i+1])){
					Tc+="@z";
					return 1;
				}
			}
		}
	}
	if(size>27) {
		for(i=0; i<strlen(str); i+=4)
			if(str[i..i+1]==str[i+2..i+3]) Sp++;		
		if(Sp==7) {
			Tc+="@s";//7¶Ô×Ó
			return 1;
		}
	}	
	
	for(i=0; i<strlen(str); i+=2){
		if( str[i..i+1]==str[i+2..i+3]) str1 = do_delete_Mj(str, str[i..i+1], 2);
		//rite( str1+"\n");
		//i+=2;
		if(check_hu(str1)) {
			if( B>0 ) Tc+="@G";
			return 1;
		}	
	}
	//write("not hu\n");		
	return 0;
}

int check_hu(string str)	//Ô­À´Ğ´ÁËnĞĞµÄ¶«Î÷£¬Èç½ñÊ®¼¸ĞĞ¸ã¶¨£¬ºÙºÙ£¬Ì¨ÍåµÄÍ¬Ö¾°¡¡­¡­
{
	int i=strlen(str); 
	string str1, str2, str3, str4;
	K=0;
	for(i=0; i<strlen(str); i+=2){
	
		str1 =str[i..i+1];str2=str[i+2..i+3];str3=str[i+4..i+5];
		if( str1==str2 && str3==str2 ) { 
			K++;
			str = do_delete_Mj(str, str1, 3);
			i=-2;}
		str2 = next_mj(str1, 1); str3= next_mj(str1, 2);
		
		if( do_check_Mj( str, str3)>0 &&do_check_Mj( str, str2 )>0 ){		
			//write("the next is "+str2+" ");
			if( str1+str2+str3==str4 ) B++;
			str = do_delete_Mj(str, str1, 1);
			str = do_delete_Mj(str, str2, 1);
			str = do_delete_Mj(str, str3, 1);
			str4 = str1+str2+str3;
			i=-2;
		}		
	}
	if( str=="" ) return 1;	
	return 0;
}

int do_touch(string str,object me)
{
	int i,check;
	mapping who;	
 
	if (!me) me=this_player();
	if (check_id(me->query("id"),"player")!="");
	else {
	   command("stare "+me->query("id"));
	   command("say ÕâÅÆ¾Ö¸úÄãÃ»¹ØÏµ¡£");
	   return 1;
	}
	if (!Playing){
	   command("say ÅÆ¾Ö»¹Ã»¿ªÊ¼ÄãÒªÃşÅÆÈ¥²ØÆğÀ´¨Ú~~");
	   return 1;
	}
//	tell_object(me,"»»Ë­ÃşÅÆ£º"+NowPlayerId[NowPlayer]+"\n");
	if (me->query("id")!=NowPlayerId[NowPlayer]){
	   command("hammer "+me->query("id"));
	   command("say ÏëÍµÅÆ£¡Ã»ÄÇ÷áÈİÒ×~~");
	   return 1;
	}
	if (me->query("id")==P1Data["Id"]) who=P1Data;
	else if (me->query("id")==P2Data["Id"]) who=P2Data;
	else if (me->query("id")==P3Data["Id"]) who=P3Data;
	else if (me->query("id")==P4Data["Id"]) who=P4Data;
	
	if(NowPlayerId[NowPlayer]==me->query("id") && Touched==1&& userp(me) ){
		do_dump( who["Mj"][0..1], me);
		return 1;
	}
	if (Touched){
	   command("flop "+me->query("id"));
	   command("say ´òÅÆÀ²£¡");
	   return 1;
	}
	if (PAUSE){
	   command("flop "+me->query("id"));
	   command("say µÈµÈ£¬ÓĞÈËÔÚ¿´ÅÆ£¡");
	   return 1;
	}
	
	NO_HU=0;
	NO_GON=0;
	
	if (who["Auto"]=="auto"){
	   if (str=="AUTO");
	   else{
	     write("Éè¶¨×Ô¶¯ÌıÅÆºó¡¢²»¿É×Ô¼ºÃşÅÆ¡£\n");
	      return 1;
	    }
	}
	Touched=1;
	str=List[count..count+1];
	count+=2;	
	tell_room(environment(this_object()),me->name()+"ÃşÁËÒ»ÕÅÅÆ¡£",me);
	
	if(userp(me)) tell_object(me,"ÄãÃşÁËÒ»ÕÅÅÆ¡£");
	//tell_object(me,"ÄãÃşµ½Ò»ÕÅ"+do_check_num(str,0)+"\n");
	if (who["Auto"]=="auto"){
	   if (do_check_num(str,1) > 34){
	      for (i=0;i<1;i++){
		   who["OutFlower"]+=str;
		   HU_F=1;
		   tell_room(environment(this_object()),me->name()+"ËµµÀ£º"+HIB+"»¨ÅÆ"+NOR+"²¹»¨£¡\n\n"+me->name()+"ÍùºóÃæ²¹ÁËÒ»ÕÅÅÆ¡£\n",me);
		   tell_object(me,"ÄãËµµÀ£º"+HIB+"»¨ÅÆ"+NOR+"²¹»¨£¡¡£\n\nÄãÍùºóÃæ²¹ÁËÒ»ÕÅÅÆ¡£\n");
		   str=List[end..end+1];
		   end-=2;
		   tell_object(me,"ÄãÃşµ½ÁËÒ»ÕÅ"+do_check_num(str,0)+"\n");
		   if (do_check_num(str,1) > 34) i--;
	      }
	   }
	   check=do_check_Mj(who["AutoTin"],str);
	   if (check!=0){
	      who["Mj"]+=str;
	      who["Mj"]=sort_data(who["Mj"]);
	      return do_win(str,me);
	   }
	   do_dump(str,me);
	}
	who["Mj"]=str+who["Mj"];
	check_flower(who);
	if( !userp(me) ) 
		if(do_check_Mj(who["OutPon"],str)>1&&do_check_num(str, 1)>27&&do_check_num(str, 1)<35 )
			do_gon( str, me);
	i=0;
	if (who["Show"]=="´úÂë") i=3;
	if (who["Show"]=="color") i=5;
	if(userp(me)) tell_object(me,"»¹ÓĞ"+chinese_number((end-count-16-Goned)/2)+"ÕÅÅÆ¾ÍÁ÷¾ÖÁË¡£\n"+show_mj(who["Mj"],i));
	
	if( !userp(me) ){
		who["Mj"]=sort_data(who["Mj"]);
		dump_what( me ); //Èç¹ûÃşÅÆÕßÊÇµçÄÔ£¬µ÷ÓÃº¯Êı¼ÆËã³öÊ²Ã´ÅÆ¡£		
	}
	return 1;
}
int do_pon(string str,object me)
{
	int i;
	mapping who, lastwho;
 
	if (!me) me=this_player();
	if (check_id(me->query("id"),"player")!="");
	else {
	   command("stare "+me->query("id"));
	   command("say ÕâÅÆ¾Ö¸úÄãÃ»¹ØÏµ¡£");
	   return 1;
	}
	if (!Playing){
	   command("die "+me->query("id"));
	   command("say ÅÆ¾Ö»¹Ã»¿ªÊ¼£¡ÅöÄãµÄÍ·À²£¡");
	   return 1;
	}
	if (Touched){
	   command("hammer "+me->query("id"));
	   command("say ±ğÈËÃ»´òÅÆÄãÔõ÷áÅö¡£");
	   return 1;
	}
	if (LastDumpId==me->query("id")){
	   command("stare "+me->query("id"));
	   command("say ÄÇÕÅÅÆÊÇÄã×Ô¼º´òµÄ!¡£");
	   return 1;
	}
	if (!str) str=LastDump;
	else if (str!=LastDump) return notify_fail("ÄÇÕÅ"+do_check_num(str,0)+"ÒÑ¾­¹ıÆÚÁË¡£\n");
	if (me->query("id")==P1Data["Id"]) who=P1Data;
	else if (me->query("id")==P2Data["Id"]) who=P2Data;
	else if (me->query("id")==P3Data["Id"]) who=P3Data;
	else if (me->query("id")==P4Data["Id"]) who=P4Data;
	if (who["Auto"]=="auto") return 1;
	i=do_check_Mj(who["Mj"],str);
	if (i==0) return notify_fail("ÄãÃ»"+do_check_num(str,0)+"ÕâÕÅÅÆÒªÔõ÷áÅö¡£\n");
	if (i < 2) return notify_fail("ÄãÊÖÖĞÒªÓĞÁ½ÕÅ"+do_check_num(str,0)+"²ÅÄÜÅö¡£\n");
	message_vision("\n$N´ó½Ğ£º"+do_check_num(str,0)+"¡«"+HIW+"Ê¯K¡«¡«¡«"+NOR+"\n\n",me);	
	//remove_call_out("do_touch");//²»ÄÜÈÃNPCÃşÅÆ£¨×Ô´ÓÁËnext_dataº¯ÊıÖ®ºó£¬Õâ¾äºÃÏóÃ»ÓĞÓÃ¿©¡£:P£©
	PAUSE = 0;		//È¡ÏûÔİÍ£
	if(userp(me)) who["Pause"]="";//È¡ÏûÍæ¼ÒµÄÔİÍ£±ê¼Ç
	destop+=str;		//°ÑÅöÁËµÄÅÆ
	destop+=str;		//°ÚÉÏ×ÀÃæ
	for (i=0;i<Play;i++) {
	    if (NowPlayerId[NowPlayer]==me->query("id")) break;
	    NowPlayer++;
	    NowPlayer%=Play;
	}
	for (i=0;i<3;i++) who["OutPon"]+=str;
	who["Mj"]=do_delete_Mj(who["Mj"],str,2);
	who["AutoPon"]=do_delete_Mj(who["AutoPon"],str,1);
	NO_HU=1;
	NO_GON=1;
	Touched=1;
	//°ÑÅöµÄÅÆ´Ó³öÅÆÕßÃæÇ°ÄÃµô£¡
	lastwho = next_data( LastDumpId, 0, "data");
	lastwho["Dump"] = do_delete_Mj(lastwho["Dump"], str, 1);	
	//ÔÙÏÔÊ¾ËùÓĞµÄÅÆ£¬ÕâÑù¿ÉÒÔ¸üºÃµÄ°ÑÎÕ£¡£¡		»¹ÊÇ²»Òª°É£¡
	/*for(i=0; i<4; i++)
		tell_room(environment(this_object()),next_data(LastDumpId , i, "id")+ "Ç°ÃæµÄÅÆÊÇ£º\n"+show_mj(next_data(LastDumpId, i, "allout"), 5));*/
	if(userp(me)) tell_object(me, "ÒÔÏÂÊÇÄãµÄÅÆ£º\n");
	i=0;
	if (who["Show"]=="´úÂë") i=3;
	if (who["Show"]=="color") i=5;	
	tell_object(me,show_mj(who["Out"]+who["OutPon"],i));
	tell_object(me,show_mj(who["Mj"],i));
	
	//Èç¹ûÅöµÄÊÇµçÄÔ£¬×Ô¶¯µ÷ÓÃ³öÅÆº¯Êı	 
	if( !userp(me) ) call_out( "dump_what", DELAY, me );	    
	
	return delete_last_dump(who["Id"]);
}
int do_restart(string str)
{
	object me=this_player();
	if (me->query("id")=="guest") return 0;
	if (str!="mj"){
	   if (check_id(me->query("id"),"player")!="");
	   else {
	      command("stare "+me->query("id"));
	      command("say ÕâÅÆ¾Ö¸úÄãÃ»¹ØÏµ¡£");
	      return 1;
	   }
	}
	message_vision("$N°ÑÅÆ¾ÖÖØĞÂÉè¶¨¡£\n",me);
	message_vision("$NËµµÀ£ºÅÆ¾ÖÖØĞÂÉè¶¨ÇëÓÃ"+HIR+" sit "+NOR+"¼ÓÈëÅÆ¾Ö¡£\n",this_object());
	NowPlayerId[0]="xishi";
	NowPlayerId[1]="chenyuanyuan";
	NowPlayerId[2]="hongniangzi";
	NowPlayerId[3]="";
	P1Data["Id"]="xishi";
	P2Data["Id"]="chenyuanyuan";
	P3Data["Id"]="hongniangzi";
	P4Data["Id"]="";
	P1Data["Pause"]="";
	P2Data["Pause"]="";
	P3Data["Pause"]="";
	P4Data["Pause"]="";
	Count=0;
	LookP ="";
	Play=START;
	Times=START;
	end=END;
	count=START;
	Playing=START;
	PAUSE = 0;
	return 1;
}
int wash_mj(int amount)
{
	int i,x;
	string str,countstr="";
	mapping who;
	object ob;
	mixed *X,MjE_Data = ([
"1w" : 0,"2w" : 0,"3w" : 0,"4w" : 0,"5w" : 0,"6w" : 0,"7w" : 0,"8w" : 0,"9w" :0,
"1s" : 0,"2s" : 0,"3s" : 0,"4s" : 0,"5s" : 0,"6s" : 0,"7s" : 0,"8s" : 0,"9s" :0,
"1t" : 0,"2t" : 0,"3t" : 0,"4t" : 0,"5t" : 0,"6t" : 0,"7t" : 0,"8t" : 0,"9t" :0,
"df" : 0,"nf" : 0,"xf" : 0,"bf" : 0,"hz" : 0,"fa" : 0,"ba" : 0,
"h1" : 0,"h2" : 0,"h3" : 0,"h4" : 0,"h5" : 0,"h6" : 0,"h7" : 0,"h8" : 0
			    ]);
	if (!Play){
	   command("say Ã»ÓĞÍæ¼ÒÒªÎÒ°×Ï´ÅÆ£¿ÃÅ¶¼Ã»ÓĞ¡£");
	   return 1;
	}
	if (Playing){
	   command("say ÅÆ¾ÖÕıÔÚ½øĞĞÖĞ¡£");
	   return 1;
	}
	command("say ÎÒ°ïÃ¦Ï´ÅÆ£¬µÈµÈË­ºúÒª³Ôºìà¸..:)");
	if (Play<4) command("say Íæ¼Ò²»×ãËÄÈËËùÒÔ²»¼Æ·Ö¡£");
	for(i=0; i<4; i++){
		who = next_data( P1Data["id"], i, "data");
		
		who["Mj"]="";
		who["OutGon"]="";
		who["Out"]="";
		who["OutPon"]="";
		who["OutFlower"]="";
		who["Auto"]="";
		who["AutoTin"]="";
		who["AutoGon"]="";
		who["AutoPon"]="";
		who["Dump"]="";
	}
 
	end=END;
	NO_HU=START;
	NO_GON=START;
	count=START;
	Playing=START;
	List="";
	NowPlayer=START;
	Touched=START;
	Auto=START;
	Auto_Tin=START;
	Auto_Gon=START;
	Auto_Pon=START;
	Goned=START;
	LastDump="";
	LastDumpId="";
	X = keys(MjE_Data);
	for (i=0;i<144;i++){
	    x = random(sizeof(X));
	    
	    if (X[x]=="h1"||X[x]=="h2"||X[x]=="h3"||X[x]=="h4"||
		X[x]=="h5"||X[x]=="h6"||X[x]=="h7"||X[x]=="h8"){
		   List += X[x];
		   X -= ({X[x]});
	    }
	    else{	       
		  MjE_Data[X[x]] = MjE_Data[X[x]] + 1;
		  List += X[x];
		  if(MjE_Data[X[x]] == 4) X -= ({X[x]});		  
	    }
	}
 
//	for (i=0;i<sizeof(X);i++) printf("%s=%d ",X[i],MjE_Data[X[i]]);
	PAUSE = 0;
	command("say àÅ£¡ºÃÁË¿ÉÒÔ¿ªÊ¼ÁËÀ´°É£¡");
	if (Count) countstr="[Á¬×¯"+chinese_number(Count)+"]";
	if (!Times);
	else{
	  if (Count);
	  else {
	    str=NowPlayerId[0];
	    if (Play>1) NowPlayerId[0]=NowPlayerId[1];
	    if (Play>2) NowPlayerId[1]=NowPlayerId[2];
	    if (Play>3) NowPlayerId[2]=NowPlayerId[3];
	    NowPlayerId[Play-1]=str;
	  }
	}
	if (Times/Play == 4) Times=0;
	if (Times/Play == 3) str=HIW+"±±·ç"+NOR;
	if (Times/Play == 2) str=HIY+"Î÷·ç"+NOR;
	if (Times/Play == 1) str=HIR+"ÄÏ·ç"+NOR;
	if (Times/Play == 0) str=HIG+"¶«·ç"+NOR;
	TIMES = str;
	i=Times;
	i%=Play;
	i++;
	message_vision("["+str+chinese_number(i)+"]ÅÆ¾Ö¿ªÊ¼£º×¯¼Ò"+HIY+NowPlayerName[0]+HIR+countstr+NOR+"ÖÀ³ö÷»×Ó"+" ["+HIR+chinese_number(i=3+random(16))+NOR+ "] µã¡£\n",this_object());
	//Íæ¼ÒÈ¡ÅÆÒ»´ÎÈ¡16Ö»:Q
	if (Play>0) P1Data["Mj"]=List[0..25];//"9t9t9tdfdf3t4t5t2s7s";P1Data["Out"]="2t3t4t";
	if (Play>1) P2Data["Mj"]=List[26..51];//"1s2s3s4s5s9s3t";P2Data["Out"]="1w2w3w4w5w6w";//
	if (Play>2) P3Data["Mj"]=List[52..77];
	if (Play>3) P4Data["Mj"]=List[78..103];//"1w1w2w2w3w3w5w5w6w6w7w7w8w";//"1t1t2t2t3t3t5w5w51s1s1s3t";//
	count=(Play*2*13);
	
	if (Play>0) check_flower(P1Data);
	if (Play>1) check_flower(P2Data);
	if (Play>2) check_flower(P3Data);
	if (Play>3) check_flower(P4Data);
	List[end..end+1]="2t";
	P1Data["Mj"] = sort_data(P1Data["Mj"]);
	P2Data["Mj"] = sort_data(P2Data["Mj"]);
	P3Data["Mj"] = sort_data(P3Data["Mj"]);
	P4Data["Mj"] = sort_data(P4Data["Mj"]);
	Playing=1;
	/*for( i=0; i<3; i++) {
		ob = next_data(NowPlayerId[0], i+1, "player");
		if(userp(ob)) tell_object( ob, "ÒÔÏÂÊÇÄãµÄÅÆ£º\n" +show_mj(next_data(NowPlayerId[0], i+1, "Mj"), 5) );		
	}*/
	get_attitudes(P1Data);get_attitudes(P2Data);get_attitudes(P3Data); //¾ö¶¨NPCµÄ´òÅÆÌ¬¶È
	message_vision("$NËµµÀ£º×¯¼Ò"+HIY+NowPlayerName[0]+NOR+"Çë³öÅÆ¡£\n",this_object());
	do_touch( 0, present(NowPlayerId[0]) );	//ÈÃ×¯¼ÒÃşÅÆ¡£	
	
	return 1;
}
int do_setmj(string str)
{
	int check;
	string numstr;
	mapping who;
	object me=this_player();
 
	if (me->query("id")==P1Data["Id"]) who=P1Data;
	else if (me->query("id")==P2Data["Id"]) who=P2Data;
	else if (me->query("id")==P3Data["Id"]) who=P3Data;
	else if (me->query("id")==P4Data["Id"]) who=P4Data;
	else return 1;
	if (!str){
	   numstr=this_object()->name()+"¶Ô×ÅÄãËµÄãÉè¶¨µÄÓĞ£º\n";
	  if (who["AutoTin"]!="") numstr+="Óöµ½"+HIB+show_mj(who["AutoTin"],2)+NOR+"»á×Ô¶¯"+HIB+"[ºúÅÆ]"+NOR+"¡£\n";
	  if (who["AutoGon"]!="") numstr+="Óöµ½"+HIY+show_mj(who["AutoGon"],2)+NOR+"»á×Ô¶¯"+HIY+"[¸ÜÅÆ]"+NOR+"¡£\n";
	  if (who["AutoPon"]!="") numstr+="Óöµ½"+HIG+show_mj(who["AutoPon"],2)+NOR+"»á×Ô¶¯"+HIG+"[ÅöÅÆ]"+NOR+"¡£\n";
	  if (who["Show"]=="´úÂë")    numstr+="ÏÔÊ¾·½Ê½Îª"+HIY+"[´úÂë]"+NOR+"·½Ê½¡£\n";
	  if (who["Show"]=="color")   numstr+="ÏÔÊ¾·½Ê½Îª"+HIG+"[²ÊÉ«]"+NOR+"¡£\n";
	  if (who["Auto"]=="auto")    numstr+="ÄãÉè¶¨"+HIR+"[×Ô¶¯ÌıÅÆ]"+NOR+"¡£\n";
	  if (who["AutoTin"]==""&&who["AutoGon"]==""&&who["AutoPon"]==""&&who["Show"]==""&&who["Auto"]=="") numstr+="ÄãÃ»ÓĞÈÎºÎÉè¶¨¡£\n";
	   tell_room(environment(me),this_object()->name()+"ÔÚ"+me->name()+"¶ú±ßËµÁËÒ»Ğ©»°¡£\n",me);
	   tell_object(me,numstr);
	   return 1;
	}
	if (sscanf(str,"%s %s",str,numstr)!=2) return notify_fail("Ö¸Áî£ºsetmj <ting>&<gang>&<peng> <´úÂë>\n");
	if (str=="ting"){
	   if (numstr=="none"){
	      who["AutoTin"]="";
	      return notify_fail("ÄãÈ¡Ïû×Ô¶¯ºúÅÆÉè¶¨¡£\n");
	   }
	   check=do_check_Mj(MjE,numstr);
	   if (check!=1) return notify_fail("Ã»ÓĞ["+numstr+"]ÕâÖÖÅÆ¡£\n");
	   check=do_check_Mj(who["AutoTin"],numstr);
	   if (check){
	      who["AutoTin"]=do_delete_Mj(who["AutoTin"],numstr,1);
	      return notify_fail("Äã"+HIR+"É¾µôÁË"+NOR+"Óöµ½"+do_check_num(numstr,0)+"»á×Ô¶¯ºúÅÆµÄÉè¶¨¡£\n");
	   }
	   who["AutoTin"]+=numstr;
	   Auto_Tin=1;
	   write("ÄãÉè¶¨Óöµ½"+do_check_num(numstr,0)+"Ê±»á×Ô¶¯ºúÅÆ¡£\n");
	   return 1;
	}
	else if (str=="gang"){
	   if (numstr=="none"){
	      who["AutoGon"]="";
	      return notify_fail("ÄãÈ¡Ïû×Ô¶¯¸ÜÅÆÉè¶¨¡£\n");
	   }
	   check=do_check_Mj(who["Mj"],numstr);
	   if (check==0) return notify_fail("ÄãÃ»"+do_check_num(numstr,0)+"ÕâÕÅÅÆ¡£\n");
	   if (check < 3) return notify_fail("ÄãÊÖÖĞÒªÓĞÈıÕÅ"+do_check_num(numstr,0)+"²ÅÄÜÉè¶¨¸Ü´ËÅÆ¡£\n");
	   check=do_check_Mj(who["AutoGon"],numstr);
	   if (check){
	      who["AutoGon"]=do_delete_Mj(who["AutoGon"],numstr,1);
	      return notify_fail("Äã"+HIR+"É¾µôÁË"+NOR+"Óöµ½"+do_check_num(numstr,0)+"»á×Ô¶¯¸ÜÅÆµÄÉè¶¨¡£\n");
	   }
	   who["AutoGon"]+=numstr;
	   Auto_Gon=1;
	   write("ÄãÉè¶¨Óöµ½"+do_check_num(numstr,0)+"Ê±»á×Ô¶¯¸ÜÅÆ¡£\n");
	   return 1;
	}
	else if (str=="peng"){
	   if (numstr=="none"){
	      who["AutoPon"]="";
	      return notify_fail("ÄãÈ¡Ïû×Ô¶¯ÅöÅÆÉè¶¨¡£\n");
	   }
	   check=do_check_Mj(who["Mj"],numstr);
	   if (check==0) return notify_fail("ÄãÃ»"+do_check_num(numstr,0)+"ÕâÕÅÅÆ¡£\n");
	   if (check < 2) return notify_fail("ÄãÊÖÖĞÒªÓĞÁ½ÕÅ"+do_check_num(numstr,0)+"²ÅÄÜÉè¶¨Åö´ËÅÆ¡£\n");
	   check=do_check_Mj(who["AutoPon"],numstr);
	   if (check){
	      who["AutoPon"]=do_delete_Mj(who["AutoPon"],numstr,1);
	      return notify_fail("Äã"+HIR+"É¾µôÁË"+NOR+"Óöµ½"+do_check_num(numstr,0)+"»á×Ô¶¯ÅöÅÆµÄÉè¶¨¡£\n");
	   }
	   who["AutoPon"]+=numstr;
	   Auto_Pon=1;
	   write("ÄãÉè¶¨Óöµ½"+do_check_num(numstr,0)+"Ê±»á×Ô¶¯ÅöÅÆ¡£\n");
	   return 1;
	}
	else if (str=="show"){
	   if (numstr=="none"||numstr=="1"){
	      who["Show"]="";
	      return notify_fail("ÄãÈ¡ÏûÏÔÊ¾Éè¶¨¡£\n");
	   }
 
	   if (numstr=="´úÂë"||numstr=="3"){
	      numstr="´úÂë";
	      write("ÄãÉè¶¨Ö»ÏÔÊ¾´úÂë¡£\n");
	   }
	   else if (numstr=="color"||numstr=="2"){
		numstr="color";
		 write("ÄãÉè¶¨²ÊÉ«ÏÔÊ¾¡£\n");
	   }
	   else return 1;
	   who["Show"]=numstr;
	   return 1;
	}
	else if (str=="auto"){
	   if (numstr=="none"){
	      return notify_fail("²»ÄÜÈ¡Ïû×Ô¶¯ÌıÅÆ£¬ÒªÊÇÉè¶¨´íÎóµÈ×ÅÕ©ºú°É£¡:>¡£\n");
	   }
	   if (who["AutoTin"]=="") return notify_fail("ÇëÏÈÉè¶¨ÒªÌıµÄÅÆ¡£\n");
	   if (!Touched) return notify_fail("ÇëÏÈÃşÅÆÔÙ×ö´ËÉè¶¨¡£\n");
	   if (numstr=="ting") write("ÄãÉè¶¨×Ô¶¯ÌıÅÆ¡£\n");
	   else return 1;
	   message_vision("\n$N´ó½ĞÒ»Éù£º"+HIW+"ÎÒÌıÀ²¡«¡«¡«"+NOR+"\n\n",me);
	   Auto=1;
	   who["Auto"]="auto";
	   return 1;
	}
	else return notify_fail("Ã»ÓĞÕâÖÖÉè¶¨¡£\n");
}
int do_check_eat(string num1,string num2,string LastDump)
{
	int A,B,C;
	A=do_check_num(num1,1);
	B=do_check_num(num2,1);
	C=do_check_num(LastDump,1);
	if (A<10){
	   if (B>10||C>10) return 0;
	}
	else if (A<19&&A>10){
		if (B>19||C>19&&B<10||C<10) return 0;
	}
	else if (A<28&&A>19){
		if (B<19||C<19) return 0;
	}
	A=do_check_num(num1,2);
	B=do_check_num(num2,2);
	C=do_check_num(LastDump,2);
 
	if (A > 9 || B > 9 || C > 9) return 0;
	if ((A+B)%2!=0){
	   if (A > B){
	       if (C==(A+1) || C==(A-2)) return 1;
	   }else{
	       if (C==(B+1) || C==(B-2)) return 1;
	   }
	   return 0;
	}else{
	    if (A > B){
	      if (C==(A-1) || C==(B+1)) return 1;
	     }else{
	      if (C==(B-1) || C==(A+1)) return 1;
	     }
	    return 0;
	}
}
string show_mj(string str,int flag)
{
	string str1, str2;       
		
	string Mj="",Mj1="";
	int size=strlen(str)+2,a,b;
	
	if(sizeof(str)>60){		
		str1 = str[sizeof(str)-60..sizeof(str)-1];
		str2 = str[0..sizeof(str)-61];
		str = show_mj( str1, flag) + show_mj(str2, flag);
		return str;
	}
	
	if (!str||str=="") return "";
	if (flag!=3){
	   for(; size>=0; size-=2)
	     Mj+=do_check_num(str[size..size+1],0);

	   for(a=0; a<size; a+=2) 
	   	Mj+=do_check_num(str[a..a+1], 0);
	   if (flag==2) Mj1=Mj;
	   else{
 
	     size=strlen(Mj);
	     Mj1="©°";
	     for (a=0;a<(size/2)-1;a++){
		 if (a%2==0) Mj1+="©¤";
		 else Mj1+="©Ğ";
	     }
	     Mj1+="©´\n©¦";
 
	     for (a=0;a<size-1;a++){
		 if (flag==5 || flag==6){
		    if (Mj[a+2..a+3]=="Íò") Mj1+=HIR;
		    else if (Mj[a+2..a+3]=="Í²") Mj1+=HIC;
		    else if (Mj[a+2..a+3]=="Ë÷") Mj1+=HIG;
		    else if (Mj[a+2..a+3]=="·ç") Mj1+=HIM;
		    else if (Mj[a+2..a+3]=="ÖĞ") Mj1+=HIR;
		    else if (Mj[a+2..a+3]=="·¢") Mj1+=HIG;
		    else if (Mj[a+2..a+3]=="°å") Mj1+=HIW;
		    else if (Mj[a+2..a+3]=="´º"
			 ||  Mj[a+2..a+3]=="ÏÄ"
			 ||  Mj[a+2..a+3]=="Çï"
			 ||  Mj[a+2..a+3]=="¶¬") Mj1+=HIR;
		    else if (Mj[a+2..a+3]=="Ã·"
			 ||  Mj[a+2..a+3]=="À¼"
			 ||  Mj[a+2..a+3]=="Öñ"
			 ||  Mj[a+2..a+3]=="¾Õ") Mj1+="[1;30m";
		 }
		 Mj1+=Mj[a..a+1];
		 a+=3;
		 Mj1+=NOR+"©¦";
	     }
	     Mj1+="\n©¦";
	     for (a=2;a<size;a++){
		 if (flag==5 || flag==6){
			 if (Mj[a..a+1]=="Íò") Mj1+=HIR;
		    else if (Mj[a..a+1]=="Ë÷") Mj1+=HIG;
		    else if (Mj[a..a+1]=="Í²") Mj1+=HIC;
		    else if (Mj[a..a+1]=="·ç") Mj1+=HIM;
		    else if (Mj[a..a+1]=="ÖĞ") Mj1+=HIR;
		    else if (Mj[a..a+1]=="·¢") Mj1+=HIG;
		    else if (Mj[a..a+1]=="°×") Mj1+=HIW;
		    else if (Mj[a..a+1]=="´º") Mj1+=HIG;
		    else if (Mj[a..a+1]=="ÏÄ") Mj1+=HIB;
		    else if (Mj[a..a+1]=="Çï") Mj1+=HIY;
		    else if (Mj[a..a+1]=="¶¬") Mj1+=HIW;
		    else if (Mj[a..a+1]=="Ã·") Mj1+=HIW;
		    else if (Mj[a..a+1]=="À¼") Mj1+=HIR;
		    else if (Mj[a..a+1]=="Öñ") Mj1+=HIG;
		    else if (Mj[a..a+1]=="¾Õ") Mj1+=HIY;
		 }
		 Mj1+=Mj[a..a+1];
		 a+=3;
		 Mj1+=NOR+"©¦";
	     }
	     Mj1+="\n©¸";
	     for (a=(size/2)-1;a>0;a--){
		 if (a%2!=0){
		    if (flag==0 || flag==5) Mj1+=str[a-1..a];
		    else Mj1+="©¤";
		 }
		 else Mj1+="©Ø";
	     }
	     Mj1+="©¼\n";
	   }
	   return Mj1;
	}else{
	    size*=2;
	    for (a=(size/2)-1;a>0;a--){
		if (a%2!=0) Mj1+=str[a-1..a];
		else Mj1+=" ";
	   }
	   Mj1+="\n";
	}
	return Mj1;
}
string check_id(string str,string kind)
{
	int check,i;
	if (!str) return "";
	if (kind=="ting")
	{
		check=NowPlayer;
		for (i=0;i<Play-1;i++)
		{
			if (NowPlayerId[check]==P1Data["Id"] && do_check_Mj(P1Data["AutoTin"],str)!=0) return P1Data["Id"];
			if (NowPlayerId[check]==P2Data["Id"] && do_check_Mj(P2Data["AutoTin"],str)!=0) return P2Data["Id"];
			if (NowPlayerId[check]==P3Data["Id"] && do_check_Mj(P3Data["AutoTin"],str)!=0) return P3Data["Id"];
			if (NowPlayerId[check]==P4Data["Id"] && do_check_Mj(P4Data["AutoTin"],str)!=0) return P4Data["Id"];
			check++;
			check%=Play;
		}
		return "";
	}
	if (kind=="gang")
	{
		check=do_check_Mj(P1Data["AutoGon"],str);
		if (check!=0)
		{
			check=do_check_Mj(P1Data["Mj"],str);
			if (check < 3) return "";
			else return P1Data["Id"];
		}
		check=do_check_Mj(P2Data["AutoGon"],str);
		if (check!=0)
		{
			check=do_check_Mj(P2Data["Mj"],str);
			if (check < 3) return "";
			else return P2Data["Id"];
		}
		check=do_check_Mj(P3Data["AutoGon"],str);
		if (check!=0)
		{
			check=do_check_Mj(P3Data["Mj"],str);
			if (check < 3) return "";
			else return P3Data["Id"];
		}
		check=do_check_Mj(P4Data["AutoGon"],str);
		if (check!=0)
		{
			check=do_check_Mj(P4Data["Mj"],str);
			if (check < 3) return "";
			else return P4Data["Id"];
		}
		return "";
	}
	if (kind=="peng")
	{
		check=do_check_Mj(P1Data["AutoPon"],str);
		if (check!=0)
		{
			check=do_check_Mj(P1Data["Mj"],str);
			if (check < 2) return "";
			else return P1Data["Id"];
		}
		check=do_check_Mj(P2Data["AutoPon"],str);
		if (check!=0)
		{
			check=do_check_Mj(P2Data["Mj"],str);
			if (check < 2) return "";
			else return P2Data["Id"];
		}
		check=do_check_Mj(P3Data["AutoPon"],str);
		if (check!=0)
		{
			check=do_check_Mj(P3Data["Mj"],str);
			if (check < 2) return "";
			else return P3Data["Id"];
		}
		check=do_check_Mj(P4Data["AutoPon"],str);
		if (check!=0)
		{
			check=do_check_Mj(P4Data["Mj"],str);
			if (check < 2) return "";
			else return P4Data["Id"];
		}
		return "";
	}
	if (kind=="player")
	{
		for (i=0;i<4;i++)
		{
			if (NowPlayerId[i]==str) check=1;
		}
		if (check) return "Y";
		return "";
	}
}
int delete_last_dump(string whoId)
{
	mapping who;
	if (LastDumpId==P1Data["Id"]) who=P1Data;
	else if (LastDumpId==P2Data["Id"]) who=P2Data;
	else if (LastDumpId==P3Data["Id"]) who=P3Data;
	else if (LastDumpId==P4Data["Id"]) who=P4Data;
	if (who["Dump"]!="") who["Dump"]=do_delete_Mj(who["Dump"],LastDump,1);
	return 1;
}
//°ÑÓ¢ÎÄ×Ö×ªÎª´úÂë or ÖĞÎÄ flag 1 ¾ÍÊÇ×ªÎª´úÂë flag 2 ×ªÎª1..9
mixed do_check_num(string str,int flag)
{
	int number;
 
	if (!str) return MjC[0];
	sscanf(str,"%d%s",number,str);
	if (number == 0)
	{
		if (str=="df") number=28;
		else if (str=="nf") number=29;
		else if (str=="xf") number=30;
		else if (str=="bf") number=31;
		else if (str=="hz") number=32;
		else if (str=="fa") number=33;
		else if (str=="ba") number=34;
		else if (str=="h1") number=35;
		else if (str=="h2") number=36;
		else if (str=="h3") number=37;
		else if (str=="h4") number=38;
		else if (str=="h5") number=39;
		else if (str=="h6") number=40;
		else if (str=="h7") number=41;
		else if (str=="h8") number=42;
		else if (str=="xx") number=43;
		else if (str=="zz") number=44;
	}
	else
	{
		if (str=="w") number=0+number;
		else if (str=="t") number=9+number;
		else if (str=="s") number=18+number;
		if (flag==2)
		{
			number%=9;
			if (number==0) number=9;
		}
	}
	if (!flag) return MjC[number];
	else return number;
}

void check_flower(mapping who)
{
	string newstr = "",str=who["Mj"],temp,temp1;
	int i = strlen(str),j;
 
	for(; i>=0; i-=2){
	      //i--;	      
	   temp=str[i..i+1];
	   if (temp=="h1"||temp=="h2"||temp=="h3"||temp=="h4"||
	       temp=="h5"||temp=="h6"||temp=="h7"||temp=="h8"){
	      if (Playing && present(who["Id"])==this_player()){
		 tell_room(environment(this_object()),this_player()->name()+"ËµµÀ£º"+HIB+"»¨ÅÆ"+NOR+"²¹»¨£¡\n\n"+this_player()->name()+"ÍùºóÃæ²¹ÁËÒ»ÕÅÅÆ¡£\n",this_player());
		 tell_object(this_player(),"ÄãËµµÀ£º"+HIB+"»¨ÅÆ"+NOR+"²¹»¨£¡\n\nÄãÍùºóÃæ²¹ÁËÒ»ÕÅÅÆ¡£\n");
		 tell_object(this_player(),"ÄãÃşµ½ÁËÒ»ÕÅ"+do_check_num(List[end..end+1],0)+"\n");
	      }	      
	      HU_F=1;
	      who["OutFlower"]+=temp;	      
	      str[i..i+1]=List[end..end+1];	      
	      end-=2;
	      i+=2;	      
	      continue;
	   }
	   else newstr=temp+newstr;
	}	
	who["Mj"]=newstr;
}
int do_check_Mj(string datastr,string str)
{
	int i,check=0;
 
	for(i=0; i<strlen(datastr); i+=2)	      
		if (datastr[i..i+1]==str) check++;

	return check;
}
string do_delete_Mj(string datastr,string str,int amount)//°ÑÄ³ÅÆÈ¥µô
{
	int size=strlen(datastr),check;
	string temp="";
 
	for( ;size>=0; size-=2)
	{
//		size--;
		if (datastr[size..size+1]==str && amount!=0) amount--;
		else temp+=datastr[size..size+1];
	}
	size=strlen(temp);
	datastr=temp;
	temp="";
	for(; size>=0; size-=2)
	{
	      //size--;
		temp+=datastr[size..size+1];
	}
	return temp;
}
string sort_data(string str)
{
	int i = strlen(str),a,b,c,d;
 
	string newstr="",temp="";
	for (a=-1;a<i;a++){
	    a++;
	    for (b=a+2;b<i;b++){
		b++;
		c=do_check_num(str[a..a+1],1);
		d=do_check_num(str[b-1..b],1);
		if (c < d){
		   temp=str[a..a+1];
		   str[a..a+1]=str[b-1..b];
		   str[b-1..b]=temp;
		}
	    }
	}
	return str;
}
int do_look(string arg)
{
	int i,l;
	object me=this_player();
	string Mj="",p1o="",p2o="",p3o="",p4o="", str;
	mapping who;
 
	if (query_verb()==".")	arg="mj";
	if (query_verb()=="..") arg="chicken";
	if (query_verb()==".1") arg="1p";
	if (query_verb()==".2") arg="2p";
	if (query_verb()==".3") arg="3p";
	if (query_verb()==".4") arg="4p";
	if (query_verb()==".0") arg="all";
	if (me->query("id")==P1Data["Id"]) who=P1Data;
	else if (me->query("id")==P2Data["Id"]) who=P2Data;
	else if (me->query("id")==P3Data["Id"]) who=P3Data;
	else if (me->query("id")==P4Data["Id"]) who=P4Data;
	else return 0;
	if (who["Auto"]=="auto") l=1;
	if (arg=="1p"||arg=="2p"||arg=="3p"||arg=="4p"||arg=="all"||arg=="chicken"||arg=="end"||arg=="dump"||arg=="mj");
	else return 0;
	if (arg=="1p") who=P1Data;
	if (arg=="2p") who=P2Data;
	if (arg=="3p") who=P3Data;
	if (arg=="4p") who=P4Data;
	if (arg=="1p"||arg=="2p"||arg=="3p"||arg=="4p"){
	   i=0;
	   if (who["Show"]=="´úÂë") i=3;
	   if (who["Show"]=="color") i=5;
	   if (!Playing||check_id(me->query("id"),"player")==""||l==1){
	      if (who["OutGon"]!=""){
		 Mj+=who["Id"]+"£º°µ¸ÜµÄÅÆÓĞ£º\n";
		 Mj+=show_mj(who["OutGon"],i+1);
	      }
	      Mj+=who["Id"]+"£ºÊÖÖĞµÄÅÆÓĞ£º\n";
	      Mj+=show_mj(who["Mj"],i);
	   }
	   Mj+=who["Id"]+"£º°Ú\ÔÚÍâÃæµÄÅÆÓĞ£º\n";
	   Mj+=show_mj(who["Out"]+who["OutPon"]+who["OutFlower"],i+1);
	   Mj+=who["Id"]+"£º´ò¹ıµÄÅÆ£º\n";
	   Mj+=show_mj(who["Dump"],2);
	}
	else if (arg=="mj") {
	   if (!Playing) return 0;
	   if (who["OutGon"]!=""){
	      Mj+="ÄãµÄ°µ¸ÜµÄÅÆÓĞ£º\n";
	      Mj+=show_mj(who["OutGon"],1);
	   }
	   if (who["Show"]=="´úÂë") i=3;
	   if (who["Show"]=="color") i=5;
	   Mj+="Äã°ÚÔÚÍâÃæµÄÅÆÓĞ£º\n";
	   Mj+=show_mj(who["Out"]+who["OutPon"]+who["OutFlower"],i+1);
	   Mj+="ÄãÊÖÖĞµÄÅÆÓĞ£º\n";
	   Mj+=show_mj(who["Mj"],i);
	   Mj+="ÄãµÄÉè¶¨ÓĞ£º";
	}else if (arg=="all") {
	      i=0;
	      if (who["Show"]=="´úÂë") i=3;
	      if (who["Show"]=="color") i=5;	      
	      tell_object(me, "ÏÖÔÚÊÇ["+TIMES+"] ×¯¼Ò "+HIY+present(NowPlayerId[0])->query("name")
	      	+"("+NowPlayerId[0]+")"+NOR+"\n" );
	      Mj+=HIG+"¶«×À  "+NOR+present(P1Data["Id"])->query("name")+"("+P1Data["Id"]+")"+"£º°Ú\ÔÚÍâÃæµÄÅÆÓĞ£º\n";	      
	      Mj+=show_mj(next_data(P1Data["Id"], 0, "allout"),i+1);	      
	      Mj+=HIG+"ÄÏ×À  "+NOR+present(P2Data["Id"])->query("name")+"("+P2Data["Id"]+")"+"£º°Ú\ÔÚÍâÃæµÄÅÆÓĞ£º\n";
	      Mj+=show_mj(next_data(P2Data["Id"], 0, "allout"),i+1);	     
	      Mj+=HIG+"Î÷×À  "+NOR+present(P3Data["Id"])->query("name")+"("+P3Data["Id"]+")"+"£º°Ú\ÔÚÍâÃæµÄÅÆÓĞ£º\n";
	      Mj+=show_mj(next_data(P3Data["Id"], 0, "allout"),i+1);					 
	      Mj+=HIG+"±±×À  "+NOR+present(P4Data["Id"])->query("name")+"("+P4Data["Id"]+")"+"£º°Ú\ÔÚÍâÃæµÄÅÆÓĞ£º\n";
	      Mj+=show_mj(next_data(P4Data["Id"], 0, "allout"),i+1);	      
	}else if (arg=="chicken"){
		 if (Playing){
		    Mj=LookP+"ÕıÈÏÕæµÄÔÚ´òÅÆ\n";
		    Mj+="»¹Ê£ÏÂ"+sprintf("%d",(end-count-16-Goned)/2)+"Ö»ÅÆ¾ÍÁ÷¾ÖÁË¡£\n";
		    if (LastDump!="") Mj+=LastDumpId+"¸Õ¸Õ´ò³öÁË"+show_mj(LastDump,2)+"\n";
		    if (Count) Mj+=NowPlayerId[0]+"£ºÁ¬×¯"+chinese_number(Count)+"\n";
		    if (P1Data["Out"]=="" && P1Data["OutPon"]=="") p1o=HIY+"ÃÅÇå"+NOR;
		    if (P2Data["Out"]=="" && P2Data["OutPon"]=="") p2o=HIY+"ÃÅÇå"+NOR;
		    if (P3Data["Out"]=="" && P3Data["OutPon"]=="") p3o=HIY+"ÃÅÇå"+NOR;
		    if (P4Data["Out"]=="" && P4Data["OutPon"]=="") p4o=HIY+"ÃÅÇå"+NOR;
		    Mj+="1£¬¶«¼ÒÊÇ£º"+NowPlayerId[0]+p1o+"\n2£¬ÄÏ¼ÒÊÇ£º"+NowPlayerId[1]+p2o+"\n";
		    Mj+="3£¬Î÷¼ÒÊÇ£º"+NowPlayerId[2]+p3o+"\n4£¬±±¼ÒÊÇ£º"+NowPlayerId[3]+p4o+"\n";
		 }
		 else if (NowPlayerId[0]!="") Mj=LookP+"ÕıÔÚµÈÈË´òÅÆ";
		 else Mj=LookP+"Ò»Ö»Âé½«¼¦ÕıµÈÈË¼ÓÈë(addin)ÅÆ¾Ö¡£";
	}else if (arg=="end"){
	   Mj+="»¹ÓĞ"+chinese_number((end-count-16-Goned)/2)+"Ö»ÅÆ¾ÍÁ÷¾ÖÁË\n";
	}else if (arg=="dump"){
	   Mj+=LastDumpId+"¸Õ¸Õ´ò³öÁË"+show_mj(LastDump,2)+"\n";
	}
	else return 0;
	if (arg=="mj"){
	  if (who["AutoTin"]!="") Mj+="Óöµ½"+show_mj(who["AutoTin"],2)+"»á×Ô¶¯ºúÅÆ¡¢";
	  if (who["AutoGon"]!="") Mj+="Óöµ½"+show_mj(who["AutoGon"],2)+"»á×Ô¶¯  ÅÆ¡¢";
	  if (who["AutoPon"]!="") Mj+="Óöµ½"+show_mj(who["AutoPon"],2)+"»á×Ô¶¯ÅöÅÆ¡£";
	  if (who["Show"]=="´úÂë")    Mj+="ÏÔÊ¾·½Ê½Îª´úÂë·½Ê½¡£";
	  if (who["Show"]=="color")   Mj+="ÏÔÊ¾·½Ê½Îª²ÊÉ«¡£";
	  if (who["Auto"]=="auto")    Mj+="ÄãÉè¶¨×Ô¶¯ÌıÅÆ¡£";
	  if (who["AutoTin"]==""&&who["AutoGon"]==""&&who["AutoPon"]==""&&who["Show"]==""&&who["Auto"]=="") Mj+="ÄãÃ»ÓĞÈÎºÎÉè¶¨¡£\n";
	}
	printf("%s\n",Mj);
	return 1;
}
int do_help(string str)
{
	if (str=="setmj"){
write(@HELP
		       »ù  ±¾  Éè  ¶¨
	    setmj ¿ÉÓÃµÄÓĞ×Ô¶¯ºú¡¢  ¡¢Åö¡¢Ìı¡¢ÏÔÊ½·½·¨¡£
--------------------------------------------------------------------
Àı×Ó1: setmj peng 1w    Éè¶¨»á×Ô¶¯Åö1w µ±±ğÈË´ò³öÒ»ÍòÊ±»á×Ô¶¯ÅöÒ»Íò¡£
       setmj gang 1w    ×Ô¶¯¸ÜÒ»Íò¡£
       setmj ting 1w    ×Ô¶¯ºúÒ»Íò¡£
Àı×Ó2: setmj show ´úÂë  Éè¶¨ÎªÖ»ÏÔÊ¾´úÂë¡£
       setmj show color Éè¶¨Îª²ÊÉ«ÏÔÊ¾¡£
Àı×Ó3: setmj ting none  È¡Ïû»á×Ô¶¯ºúÅÆÉè¶¨¡£
       setmj gang none
       setmj peng none
Àı×Ó4: setmj auto ting  Éè¶¨×Ô¶¯ÌıÅÆ¡£
--------------------------------------------------------------------
HELP);
	return 1;
	}
	return 0;
}
int do_play()
{
write(@HELP
        Ö¸  Áî        Àı  ×Ó                         Ëµ    Ã÷
    ©°©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©´
    ©¦ sit       ----------                              ¼ÓÈëÅÅ¾Ö ©¦
    ©¦ look      l mj»ò.¿´×Ô¼ºÅÆ,l 1p»ò.1¿´Íæ¼Ò1µÄÅÆ              ©¦
    ©¦ l all»ò..¿´È«²¿,l end¿´Á÷¾Öl dump¡£               ¿´ÅÆ     ©¦
    ©¦ mo        Èç¹û¸ÕÃşÍê¾Í°´»á´òµô¸ÕÃşµÄÅÆ£¬·½±ãÌıºú  ÃşÅÆ     ©¦
    ©¦ da        da <´úÂë>¡£                             ´òÅÆ     ©¦
    ©¦ chi       chi <´úÂë1> <´úÂë2>¡£                   ³ÔÅÆ     ©¦
    ©¦ peng      ----------                              ÅöÅÆ     ©¦
    ©¦ gang      gang »ò gang <´úÂë>(°µ¸ÜÓÃ)¡£           ¸ÜÅÆ     ©¦
    ©¦ hu                                                ºúÅÆ     ©¦
    ©¦ setmj     help setmj¡£                            Éè¶¨²ÎÊı ©¦
    ©¦ start     ----------                              ÅÆ¾Ö¿ªÊ¼ ©¦
    ©¦ restart   restart »ò restart mj¡£                 ÖØĞÂ¿ªÊ¼ ©¦
    ©¦ continue  ´ßNPC»òÍæ¼Ò³öÅÆ£¬ÌØÊâÇé¿öÊ±ÌØ±ğÓĞÓÃ¡£            ©¦
    ©¦ top       top aip,top -p,top -w,top -h,top -d              ©¦
    ©¦ top -l    ¿´È«²¿,-lw,-lh,-ld¡£                    ²é×ÊÁÏ   ©¦
    ©¸©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¼
HELP);
	return 1;
}
int do_rule()
{
write(@HELP
 
¡¡¡¡Ã¿ºú¾ÍÓĞµ×Ì¨£±£¬ÔÙ¼ÓÉÏËùµÃµÄÌ¨¾ÍÊÇ×ÜÌ¨£¬ÒªÊÇ×ÔÃş¾Í£ª£³¡£
·ÅÇ¹¾ÍÓÉ×ÜÕ½¼¨ÄÇ¿ÛµôËùÊ§µÄÌ¨Êı¡£ºúÕßÔò¼ÓÉÏÈ¥¡£
 
HELP);
	return 1;
}
int show_top(string str)
{
	int i,check,a,b,c,d,e;
	string *temp=({"","","","","",""});
	string show="";
	mixed *MjData;
 
	if (!str) str=this_player()->query("id");
	else if (str=="-lp"||str=="-pl"||str=="-l") str="all1";
	else if (str=="-lw"||str=="-wl") str="all2";
	else if (str=="-lh"||str=="-hl") str="all3";
	else if (str=="-ld"||str=="-dl") str="all4";
	if (file_size(MJ_DATA)==-1) return notify_fail("×ÊÁÏµµÃ»Ã»ÓĞÕÒµ½¡£\n");
	MjData=explode(read_file(MJ_DATA),",");
	if (str=="all1") e=2;
	else if (str=="all2") e=3;
	else if (str=="all3") e=4;
	else if (str=="all4") e=5;
	if (str=="all1"||str=="all2"||str=="all3"||str=="all4") str="all";
	if (str=="-p") e=2;
	else if (str=="-w") e=3;
	else if (str=="-h") e=4;
	else if (str=="-d") e=5;
	if (str=="all"||str=="-p"||str=="-w"||str=="-h"||str=="-d")
	{
		for (a=0;a<sizeof(MjData);a+=6)
		{
			for (b=a+6;b<sizeof(MjData);b+=6)
			{
				sscanf(MjData[a+e],"%d",c);
				sscanf(MjData[b+e],"%d",d);
				if (d > c)
				{
					for (i=0;i<6;i++)temp[i]=MjData[a+i];
					for (i=0;i<6;i++) MjData[a+i]=MjData[b+i];
					for (i=0;i<6;i++) MjData[b+i]=temp[i];
				}
			}
		}
	}
	show=HBWHT+"\n  ";
	for (i=0; i<34; i++) show+="[47m¡¡";
	show+=HBWHT+"  \n";
	show+="  "+HBRED+"   Ó¢ÎÄÃû×Ö   ©¦  ÖĞÎÄÃû×Ö  ©¦ÒÑÍæ¾ÖÊı©¦ ×ÜÕ½¼£ ©¦×ÔÃş´ÎÊı©¦·ÅÇ¹´ÎÊı  "+HBWHT+"  \n";
	if (str=="all")
	{
		for (i=0; i<sizeof(MjData); i+=6)
		{
			show+="  "+HBRED;
			show+=sprintf("  %12s©¦%12s©¦%8s©¦%8s©¦%8s©¦%8s  ", MjData[i],MjData[i+1],MjData[i+2],MjData[i+3],MjData[i+4],MjData[i+5]);
			show+=HBWHT+"  \n";
		}
	}
	else if (str=="-p"||str=="-w"||str=="-h"||str=="-d")
		{
			if (sizeof(MjData) < 60) d=sizeof(MjData);
			else d=60;
			for (i=0; i<d; i+=6)
			{
				show+="  "+HBRED;
				show+=sprintf("  %12s©¦%12s©¦%8s©¦%8s©¦%8s©¦%8s  ", MjData[i],MjData[i+1],MjData[i+2],MjData[i+3],MjData[i+4],MjData[i+5]);
				show+=HBWHT+"  \n";
			}
		}
		else
		{
			for (i=0; i<sizeof(MjData); i+=6)
			{
				if (MjData[i]==str)
				{
					check=1;
					break;
				}
			}
			if (check==1)
			{
				show+="  "+HBRED;
				show+=sprintf("  %12s©¦%12s©¦%8s©¦%8s©¦%8s©¦%8s  ", MjData[i],MjData[i+1],MjData[i+2],MjData[i+3],MjData[i+4],MjData[i+5]);
				show+=HBWHT+"  \n";
			}
			else return notify_fail("Ã»ÓĞÕâ¸öÈËµÄ×ÊÁÏ¡£\n");
		}
	show+=HBWHT+"  ";
	for (i=0; i<34; i++) show+="[47m¡¡";
	show+=HBWHT+"  "+NOR+"\n";
	printf("%s\n",show);
	return 1;
}
int set_mjdata(object me,int *winner)
{
	int i,check;
	string str="";
	mixed *MjData;
 
	if (!me||!winner) return 0;
	if (file_size(MJ_DATA)==-1);
	else
	{
		MjData=explode(read_file(MJ_DATA),",");
		for (i=0; i<sizeof(MjData); i+=6)
		{
			if (MjData[i]==me->query("id"))
			{
				check=1;
				break;
			}
		}
	}
	if (check==1)
	{
		MjData[i+2]=sprintf("%d",winner[0]);
		MjData[i+3]=sprintf("%d",winner[1]);
		MjData[i+4]=sprintf("%d",winner[2]);
		MjData[i+5]=sprintf("%d",winner[3]);
		for (i=0; i<sizeof(MjData); i++) str+=MjData[i]+",";
		write_file(MJ_DATA,str,1);
	}
	else
	{
		str=me->query("id")+",";
		str+=me->name()+",";
		str+=winner[0]+",";
		str+=winner[1]+",";
		str+=winner[2]+",";
		str+=winner[3]+",";
		write_file(MJ_DATA,str,0);
	}
	return 1;
}
int *get_mjdata(string Id)
{
	int i,check,*winner=({0,0,0,0});
	string str="";
	mixed *MjData;
 
	if (!Id) return 0;
	if (file_size(MJ_DATA)==-1) return 0;
	MjData=explode(read_file(MJ_DATA),",");
	for (i=0; i<sizeof(MjData); i+=6)
	{
		if (MjData[i]==Id)
		{
			check=1;
			break;
		}
	}
	if (check==1)
	{
		sscanf(MjData[i+2],"%d",winner[0]);
		sscanf(MjData[i+3],"%d",winner[1]);
		sscanf(MjData[i+4],"%d",winner[2]);
		sscanf(MjData[i+5],"%d",winner[3]);
	}
	return winner;
}
int get_tc(mapping who)
{
	int size,i,check;
	string str,tempW="",tempT="",tempS="",tempB="";
	str=who["Mj"]+who["Out"]+who["OutPon"]+who["OutGon"];
	//×¯¼Ò
	if (NowPlayerId[0]==who["Id"]) Tc+="@1";
	//ÃÅÇå&×ÔÃş
	if (who["Out"]==""&&who["OutPon"]==""&&Touched) Tc+="@l";
	else if (who["Out"]==""&&who["OutPon"]=="") Tc+="@4";
	else if (Touched) Tc+="@2";
	//È«ÇóÈË
	if (strlen(who["Mj"]) < 5) Tc+="@i";
	size=strlen(str);
	for(; size>=0; size-=2){
	      //size--;
	  if (do_check_num(str[size..size+1],1) < 10) tempW+=str[size..size+1];
	  else if (do_check_num(str[size..size+1],1) < 19) tempT+=str[size..size+1];
	  else if (do_check_num(str[size..size+1],1) < 28) tempS+=str[size..size+1];
	  else tempB+=str[size..size+1];
	}
	//·çÅÆ
	if (Times/Play == 0 && NowPlayerId[0]==who["Id"]&&do_check_Mj(tempB,"df")>2) Tc+="@e";
	else if (Times/Play == 0 && do_check_Mj(tempB,"df") > 2
	     ||  NowPlayerId[0]==who["Id"]&&do_check_Mj(tempB,"df")>2) Tc+="@5";
	if (Times/Play == 1 &&NowPlayerId[1]==who["Id"]&&do_check_Mj(tempB,"nf")>2) Tc+="@f";
	else if (Times/Play == 1 && do_check_Mj(tempB,"nf") > 2
	     ||  NowPlayerId[1]==who["Id"]&&do_check_Mj(tempB,"nf")>2) Tc+="@6";
	if (Times/Play == 2 &&NowPlayerId[2]==who["Id"]&&do_check_Mj(tempB,"xf")>2) Tc+="@g";
	else if (Times/Play == 2 && do_check_Mj(tempB,"xf") > 2
	     ||  NowPlayerId[2]==who["Id"]&&do_check_Mj(tempB,"xf")>2) Tc+="@7";
	if (Times/Play == 3 && NowPlayerId[3]==who["Id"]&&do_check_Mj(tempB,"bf")>2) Tc+="@h";
	else if (Times/Play == 3 && do_check_Mj(tempB,"bf") > 2
	     ||  NowPlayerId[3]==who["Id"]&&do_check_Mj(tempB,"bf")>2) Tc+="@8";
	//»¨ÅÆ
	if (sizeof(who["OutFlower"]) ==16) Tc+="@A";//°ËÏÉ¹ıº£
	else if (sizeof(who["OutFlower"]) ==14&&sizeof(P1Data["OutFlower"]+P2Data["OutFlower"]+P3Data["OutFlower"]+P4Data["OutFlower"])==16) Tc+="@D";//ÆßÇÀÒ»
	else if (do_check_Mj(who["OutFlower"],"h1")==1&&do_check_Mj(who["OutFlower"],"h2")==1
	&&  do_check_Mj(who["OutFlower"],"h3")==1&&do_check_Mj(who["OutFlower"],"h4")==1) Tc+="@B";//´ºÏÄÇï¶¬
	else if (do_check_Mj(who["OutFlower"],"h5")==1&&do_check_Mj(who["OutFlower"],"h6")==1
	&&  do_check_Mj(who["OutFlower"],"h7")==1&&do_check_Mj(who["OutFlower"],"h8")==1) Tc+="@C";//Ã·À¼¾ÕÖñ
	else if (NowPlayerId[0]==who["Id"]&&do_check_Mj(who["OutFlower"],"h1")==1
	||  NowPlayerId[0]==who["Id"]&&do_check_Mj(who["OutFlower"],"h5")==1
	||  NowPlayerId[1]==who["Id"]&&do_check_Mj(who["OutFlower"],"h2")==1
	||  NowPlayerId[1]==who["Id"]&&do_check_Mj(who["OutFlower"],"h6")==1
	||  NowPlayerId[2]==who["Id"]&&do_check_Mj(who["OutFlower"],"h3")==1
	||  NowPlayerId[2]==who["Id"]&&do_check_Mj(who["OutFlower"],"h7")==1
	||  NowPlayerId[3]==who["Id"]&&do_check_Mj(who["OutFlower"],"h4")==1
	||  NowPlayerId[3]==who["Id"]&&do_check_Mj(who["OutFlower"],"h8")==1) Tc+="@3";
	//ÇåÒ»É«¸ú×ÖÒ»É«
	if (tempW!=""&&tempT==""&&tempS==""&&tempB=="") Tc+="@q";
	else if (tempW==""&&tempT!=""&&tempS==""&&tempB=="") Tc+="@q";
	else if (tempW==""&&tempT==""&&tempS!=""&&tempB=="") Tc+="@q";
	else if (tempW==""&&tempT==""&&tempS==""&&tempB!="") Tc+="@r";
	//»ìÒ»É«
	if (tempW!=""&&tempT==""&&tempS==""&&tempB!="") Tc+="@n";
	else if (tempW==""&&tempT!=""&&tempS==""&&tempB!="") Tc+="@n";
	//ÂÌÒ»É«
	else if (tempW==""&&tempT==""&&tempS!=""&&tempB!=""){
	     if (do_check_Mj(tempB,"fa")==3&&sizeof(tempB)==6
	     ||  do_check_Mj(tempB,"fa")==2&&sizeof(tempB)==4
	     && do_check_Mj(tempS,"1s")==0&& do_check_Mj(tempS,"5s")==0
	     && do_check_Mj(tempS,"7s")==0&& do_check_Mj(tempS,"9s")==0) Tc+="@E";
	     else Tc+="@n";
	}
	//´óÈıÔª
	if (do_check_Mj(tempB,"hz") > 2
	&&  do_check_Mj(tempB,"fa") > 2
	&&  do_check_Mj(tempB,"ba") > 2) Tc+="@t";
	//Ğ¡ÈıÔª
	else if (do_check_Mj(tempB,"hz") > 1
	&&  do_check_Mj(tempB,"fa") > 1
	&&  do_check_Mj(tempB,"ba") > 1) Tc+="@o";
	else if (do_check_Mj(tempB,"hz") > 2) Tc+="@9";
	else if (do_check_Mj(tempB,"fa") > 2) Tc+="@0";
	else if (do_check_Mj(tempB,"ba") > 2) Tc+="@a";
	//´óËÄÏ²
	if (do_check_Mj(tempB,"df") > 2
	&&  do_check_Mj(tempB,"nf") > 2
	&&  do_check_Mj(tempB,"xf") > 2
	&&  do_check_Mj(tempB,"bf") > 2) Tc+="@v";
	//Ğ¡ËÄÏ²
	else if (do_check_Mj(tempB,"df") > 1
	&&  do_check_Mj(tempB,"nf") > 1
	&&  do_check_Mj(tempB,"xf") > 1
	&&  do_check_Mj(tempB,"bf") > 1) Tc+="@F";
 
	for (i=0;i<sizeof(str);i+=2){
	    if (str[i..i+1]=="xx") continue;
	    if (do_check_Mj(str,str[i..i+1])==3) check++;
	    else if (do_check_Mj(str,str[i..i+1])==4) check++;
	}
	//ÅöÅöºú
	
	if ( (sizeof(who["OutPon"])+K*6)>23){
	   if (who["Out"]==""&&who["OutPon"]==""&&do_check_Mj(Tc,"@p")==0) Tc+="@m@p";
	   else  Tc+="@m";
	}
	
	check=0;
	
	for (i=0;i<sizeof(str);i+=2)//¼ì²éÓĞÃ»ÓĞÒ»¾Å
		if (do_check_num(str[i..i+1],2)==1||do_check_num(str[i..i+1],2)==9) check++;
	
	//tell_object( present("wiman"), "check is"+check+" "+who["OutPon"]+" "+K+"\n");
	if (check!=0&&tempB!=""&&(check+strlen(tempB)/2>14)) Tc+="@I";//»ìçÛ¾Å
	else if (tempB==""&&check==14) Tc+="@J";//ÇåçÛ¾Å
	
	//Æ½ºú
	
	//if (tempB==""&&who["OutFlower"]==""&&check==0&&sizeof(who["AutoTin"])>3) Tc+="@d";
	if (tempB==""&&who["OutPon"]==""&&K==0) Tc+="@d";//Æ½ºúµÄÒªÇóÃ»ÄÇÃ´¿Á¿Ì°É£¿£¿
	
	//¶ÏçÛ¾Å
	if( check==0 ) {//²»ÄÜÓĞÒ»¾Å		
		for (i=0;i<sizeof(str);i+=2)
	    //if (do_check_num(str[i..i+1],1)!=1&&do_check_num(str[i..i+1],1)>8) check++;
			if (do_check_num(str[i..i+1],1)>27 && do_check_num(str[i..i+1],1)<35) check++;
		if(check==0) Tc+="@Z";
	}
	
	//ºÓµ×ÃşÔÂ
	if (count==((end-13-(Goned*2))-2)&&Touched) Tc+="@b";
	//ÀÌÓã
	if (count==((end-13-(Goned*2))-2)&&!Touched) Tc+="@c";
	//Ììºú
	if (LastDump==""&&count==(Play*2*13)+2) Tc+="@w";
	//µØºú&ÈËºú
	//printf("%d > %d\n",count,((Play*2*16)+(Play*2)));
	if (count < ((Play*2*13)+(Play*2))
	&&P1Data["Out"]==""&&P1Data["PonOut"]==""
	&&P2Data["Out"]==""&&P2Data["PonOut"]==""
	&&P3Data["Out"]==""&&P3Data["PonOut"]==""
	&&P4Data["Out"]==""&&P4Data["PonOut"]==""){
	   if (Touched) Tc+="@x";
	   else Tc+="@y";
	}
	return 1;
}
int ch(string str)
{
	object me=this_player();
	mapping who;
	if (me->query("id")==P1Data["Id"]) who=P1Data;
	else if (me->query("id")==P2Data["Id"]) who=P2Data;
	else if (me->query("id")==P3Data["Id"]) who=P3Data;
	else if (me->query("id")==P4Data["Id"]) who=P4Data;
	if (!str) return 0;
	write("Äã°ÑÅÆ"+who["Mj"]+"»»³É"+str+" ok.\n");
	str=sort_data(str);
	who["Mj"]=str;
	return 1;
}

//ÒÔÏÂÊÇ»ÄÁ¹¼ÓÈëµÄº¯ÊıÎª£¬Ò»·½ÃæÎªÁËÄÜÈË»ú¶Ô¾Ö¶ø¼Ó£¬ÁíÍâÒ²Í¨¹ıÕ÷Ñ¯Íæ¼ÒÃÇµÄÒâ¼û¼ÓÈëÁËÒ»Ğ©ÈËĞÔ»¯µÄº¯ÊıÃüÁî¡­¡­
//´ÓÕâÀï¿ªÊ¼ÊÇÈËĞÔ»¯µÄº¯Êı
void dump_what( object me )
{
	mapping who;	
	int t,k,W,T,S,Sp;
	//string tempW="",tempT="",tempS="",tempB="", Mj;
	mapping Temp = ([ "tempW": "", "tempT": "", "tempS": "", "tempB": "" ]);	
	string Special="1w9w1s9s1t9tdfnfxfbfhzfaba"; 
	string str_out;
	int size,i;
		
	int pos;	//×Ö´®µÄÎ»ÖÃ
	
	Temp["tempB"]="";
	Temp["tempW"]="";
	Temp["tempT"]="";
	Temp["tempS"]="";	
	
	who=next_data( me->query("id"), 0, "data");
	get_all_temps( Temp, who["Mj"] );
	str_out = Temp["tempW"]+Temp["tempT"]+Temp["tempS"];
	who["3Ps"] ="";
	who["3Es"] ="";
	who["2Ps"] ="";
	who["2Es1"] ="";
	who["2Es2"] ="";
	who["1s"] ="";
	
	who["H2Ps"] ="";
	who["H2Es1"] ="";
	who["H2Es2"] ="";
	who["H1s"] ="";
	
	switch( who["Attitude"] ) {		
//ÒÔÏÂÊÇ×îcheapµÄ´ò·¨£¬ÄÜºú¾ÍĞĞ    
case "cheap" :    
//	tell_object( present("wiman"), "cheap´ò·¨ "); //ÕâÀï¿ÉĞ´ÈëÎ×Ê¦µÄÃû×ÖÒÔ±ã½øĞĞ²âÊÔ¡£
//	get_all_temps( Temp, who["Mj"] );
	if (Temp["tempB"]!="") filt_mj(Temp["tempB"], me);
	if (Temp["tempW"]!="") filt_mj(Temp["tempW"], me);
	if (Temp["tempT"]!="") filt_mj(Temp["tempT"], me);
	if (Temp["tempS"]!="") filt_mj(Temp["tempS"], me);
			break;
//ÒÔÏÂÊÇcommon´ò·¨£¬ÓĞµã½²¾¿Å¶¡£Æ½ºú¡¢ÅöÅöºú¡¢»ìÒ»É«¡¢Æß¶Ô×Ó
case "common" :	
	//tell_object( present("wiman"), "common´ò·¨ ");
//Æ½ºú
	if( dump_pinhu( who, me, Temp ) ) break;	
//´ÓÕâÒÔÏÂÊÇÅöÅöºú
	if( dump_ponpon( who, me, Temp )) break;
//´ÓÕâÒÔÏÂÊÇ»ìÒ»É«
	if( dump_twocolor( (who["Out"]+who["OutGon"]+who["OutPon"]), (Temp["tempW"]+Temp["tempT"]+Temp["tempS"]), me, Temp ) ) {
		who["Hu_type"] = "twocolor";
		break;	
	}
	break;
case "goodboy" :
	//tell_object( present("wiman"), "goodboy´ò·¨ ");//ÕâÀï¿ÉĞ´ÈëÎ×Ê¦µÄÃû×ÖÒÔ±ã½øĞĞ²âÊÔ¡£
	//tell_object( present("wiman"), who["Out"]+who["OutGon"]+who["OutPon"]+"..." );
//ÒÔÏÂÊÇÇåÒ»É«
	if( dump_samecolor( (who["Out"]+who["OutGon"]+who["OutPon"]), who["Mj"], me) ) { 
		who["Hu_type"] = "samecolor";
		break;
	}
//´ÓÕâÒÔÏÂÊÇ»ìÒ»É«
	else if( dump_twocolor( (who["Out"]+who["OutGon"]+who["OutPon"]), str_out, me, Temp ) ) {
		who["Hu_type"] = "twocolor";
		break;	
	}
//´ÓÕâÒÔÏÂÊÇÅöÅöºú
	if( dump_ponpon( who, me, Temp)) break;
//Æ½ºú
	if( dump_pinhu( who, me, Temp ) ) break;
	
	
// ÒÔÏÂÊÇÄ¬ÈÏµÄ´ò·¨	
	default :
		//tell_object( present("wiman"), "default·¨ ");
		who["Hu_type"] = "";
		if (Temp["tempB"]!="") filt_mj(Temp["tempB"], me);
		if (Temp["tempW"]!="") filt_mj(Temp["tempW"], me);
		if (Temp["tempT"]!="") filt_mj(Temp["tempT"], me);
		if (Temp["tempS"]!="") filt_mj(Temp["tempS"], me);
	}
	
	//tell_object( present("wiman"), "»ù±¾´ò·¨ ");	
	if( who["1s"]!="" ){//ÕâÀïÊÇÉ¢ÅÆµÄÇé¿ö		      	
		
		do_dump( find_mj(who["1s"], who["Mj"]), me);
		return;
	}
	else if(who["2Es2"]!="" && who["Hu_type"]!="pinhu"){//ÕâÀïÊÇ¼ä¸ôÅÆµÄÇé¿ö£¨Èç1w3w, 4t6t, 7s9sµÈ£©		
		do_dump( find_mj(who["2Es2"], who["Mj"]), me);
		return;
	}
	else if(who["2Es1"]!="" && who["Hu_type"]!="pinhu"){//ÕâÀïÊÇÁ¬ĞøÁ½¸öÅÆµÄÇé¿ö£¨Èç1w2w, 4t5t, 7s8sµÈ£©
		do_dump( find_mj(who["2Es1"], who["Mj"]), me);
		return;
	}
	else if(who["2Ps"]!="" && who["Hu_type"]!="ponpon" 
		&& do_check_win(who["Mj"])!=1){//ÕâÀïÊÇ¶ÔÅÆµÄÇé¿ö£¨Èç1w1w, 4t4t, 7s7sµÈ)
		//tell_object(present("wiman"), /*who["2Ps"]+*/"dump 2Ps?\n");
		do_dump( find_mj(who["2Ps"], who["Mj"]), me);
		return;
	}
	else if( who["3Es"]!="" && who["Hu_type"]!="pinhu" && do_check_win(who["Mj"])!=1) {
		//tell_object(present("wiman"), " 3Es!=0?\n");
		do_dump(find_mj( who["3Es"], who["Mj"]), me);return;
	}
	else if( who["3Ps"]!="" && sizeof(who["3Ps"])>5 && who["Hu_type"]!="ponpon" && do_check_win(who["Mj"])!=1) {
		do_dump(find_mj( who["3Ps"], who["Mj"]), me);return;
	}
	else if(do_check_win(who["Mj"])==1 && NO_HU!=1 ){//Èç¹ûÉÏÊöÇé¿ö¶¼Ã»ÓĞ³öÏÖ£¬ÊÇ·ñÓ¦¸ÃºúÅÆÁËÄØ£¿£¿£¿
		//tell_object(present("wiman"), NO_HU+" may i win?\n");
		call_out( "do_win", DELAY, List[count-2..count-1], me);
		return;
	}
 	//tell_object(present("wiman"), " dump random?\n");
 	do_dump(find_mj( who["Mj"], who["Mj"]), me);
	return;
}

int get_attitudes(mapping who)
{	//´Ó¡°Æ½ºú¡¢»ìÀÏÍ·¡¢Æß¶Ô×Ó¡¢ÅöÅöºú¡¢»ìÒ»É«¡¢ÇåÀÏÍ·¡¢Ğ¡ËÄÏ²¡¢Ğ¡ÈıÔª¡¢ÂÌÒ»É«¡¢ÇåÒ»É«¡¢´óÈıÔª¡¢´óËÄÏ²¡¢
	//×ÖÒ»É«¡¢Ê®ÈıçÛ¡±ÖĞÑ¡£¿£¿£¿ÔİÊ±Ö»ÓĞÁ½ÖÖ
	int i;
	i = random(100);
	if( i<40 ) { who["Attitude"] = "cheap"; who["Hu_type"] = ""; }
	else if( i<80 ) { who["Attitude"] = "common"; who["Hu_type"] = ""; }
	else if( i<100 ) { who["Attitude"] = "goodboy"; who["Hu_type"] = ""; }
	//else if( i<100 ) who["Attitude"] = "crazy";
	return 1;
}

int do_pause( object me )
{
	if(!me) me = this_player();
	if(!PAUSE) {
		PAUSE = 1;		//ÔİÍ£
		//remove_call_out( "do_touch");		
		//tell_object(me," "+HIY+"ÄãÓĞ¶şÊ®ÃëµÄÊ±¼ä¿¼ÂÇ¡­¡­"+NOR+"\n");	
		//tell_room( environment(me), me->query("id")+"´ó½Ğ£º¡°µÈÒ»µÈ£¡£¡£¡\n", me );		
		call_out( "undo_pause", 20, me);
	}
		
	return 1;
}

int undo_pause(object me)
{
	//string str;
	if(PAUSE == 0) return 1;
	else PAUSE = 0;		//È¡ÏûÔİÍ£
	
	tell_room( environment(this_object()), this_object()->query("name")+"ËµµÀ£º¡°´ó¼Ò¾¡Á¿½ô´ÕÒ»Ğ©¡£\n" );
	
	//str = NowPlayerId[NowPlayer];
	if( !userp(next_data(me->query("id"), 1, "player")) )
		do_touch( 0, next_data( me->query("id"), 1, "player") );
		//do_touch( 0, next_data(str, 0, "player") );
	return 1;
}

//NPCµÄĞĞ¶¯
int npc_action( object me )
{
	string str, str1, str2, str3;
	int i, num1, num2, num3;
	object ob;
	mapping who;
	
	for(i=0; i<3; i++) {
		//³Ôºú
		who = next_data(me->query("id"), i, "data");
		str = next_data(me->query("id"), i, "Mj");		
		who["Mj"] += LastDump;
		who["Mj"] = sort_data(who["Mj"]);
		ob = next_data(me->query("id"), i, "player");
		//tell_object(present("wiman"), ob->query("name")+ "¡ª¡ª");	
				
		if( do_check_win(who["Mj"]) ) {			
			if( !userp(ob) ){
				if(who["Attitude"]=="cheap") {
					PAUSE = 1;
					who["Mj"] = str;
					do_win( 0, ob );
					return 1; }
				else if(who["Attitude"]=="common") {
					if(get_times(who)>2) {						
						//PAUSE = 1;
						who["Mj"] = str;
						do_win( 0, ob );
						return 1; }
					else if( random((end-count-16-Goned)/2)<30 ) {						
						who["Mj"] = str;
						do_win( 0, ob );
						return 1; }
				}
				else if(who["Attitude"]=="goodboy"){
					if(get_times(who)>3) {						
						//PAUSE = 1;
						who["Mj"] = str;
						do_win( 0, ob );
						return 1; }
					else if( random((end-count-16-Goned)/2)<20 ) {
						who["Mj"] = str;
						do_win( 0, ob );
						return 1; }
				}
			}
			else {				
				tell_object(ob, show_mj(LastDump, 6) );
				tell_object(ob, show_mj(str, 6) );
				tell_object(ob, "ÊÇ·ñºú»òÅö»ò¸Ü"+ do_check_num(LastDump, 0)+"£¿£¿£¨Èç¹ûÊÇ£¬ÇëÊäÈë£ºhu/peng/gang£©\nÈç¹û·ñ£¬ÇëÊäÈëcontinue\n");
				PAUSE = 2;	//°ÑÊ±¼äÅªÍ££¬·ÀÖ¹Íæ¼Ò¶ÔÕ½Ê±ÇÀÃş¡­¡­
				who["Pause"] = "yes";
				who["Mj"] = str;				
				return 1;
			}
		}
		who["Mj"] = str;
		//ÅöÅÆ
		//tell_object(present("wiman"), "ÅöÅÆ ");
		str = who["2Ps"];
		if( !userp(ob) ) {
			/*if( do_check_Mj(str, LastDump)>1 ) {
				//PAUSE = 1;
				if( do_pon( LastDump, ob ) )
				return 1;
			}*/
			if( who["Hu_type"]=="twocolor" || who["Hu_type"]=="samecolor" ) {
				str = who["H2Ps"];
				if( do_check_Mj(str, LastDump)>1 ){
					//PAUSE = 1;
					if(do_pon( LastDump, ob )) return 1;
				}
			}
			else if( who["Hu_type"]!="pinhu") {
				if( do_check_Mj(str, LastDump)>1 ){
					//PAUSE = 1;
					if(do_pon( LastDump, ob )) return 1;
				}			
			}      		
		}
		else {	//Íæ¼ÒµÄÇé¿öÓ¦¸Ã°üº¬ÁË¸ÜÅÆµÄ¡£
			if( do_check_Mj(next_data(me->query("id"), i, "Mj"), LastDump)>2 ){
				tell_object(ob, "ÒÔÏÂÊÇÄãµÄÅÆ£º\n"+show_mj(next_data(me->query("id"), i, "Mj"), 6) );
				PAUSE = 2;	//°ÑÊ±¼äÅªÍ££¬·ÀÖ¹Íæ¼Ò¶ÔÕ½Ê±ÇÀÃş¡­¡­
				tell_object(ob, "ÊÇ·ñÅö»ò¸Ü"+ do_check_num(LastDump, 0)+"£¿£¿£¨Èç¹ûÊÇ£¬ÇëÊäÈë£ºpeng/gang£©\nÈç¹û·ñ£¬ÇëÊäÈëcontinue\n");
				who["Pause"] = "yes";				
				return 1;
			}
			else if( do_check_Mj(next_data(me->query("id"), i, "Mj"), LastDump)>1 ){
				tell_object(ob, "ÒÔÏÂÊÇÄãµÄÅÆ£º\n"+show_mj(next_data(me->query("id"), i, "Mj"), 6) );
				PAUSE = 2;	//°ÑÊ±¼äÅªÍ££¬·ÀÖ¹Íæ¼Ò¶ÔÕ½Ê±ÇÀÃş¡­¡­
				tell_object(ob, "ÊÇ·ñÅö"+ do_check_num(LastDump, 0)+"£¿£¿£¨Èç¹ûÊÇ£¬ÇëÊäÈë£ºpeng£©\nÈç¹û·ñ£¬ÇëÊäÈëcontinue\n");
				who["Pause"] = "yes";				
				return 1;
			}
       		}
	//}
	
		//NPCÔİÊ±Ö»»á¸Ü±¦ÅÆ£¬ÒòÎª¸ÜÆäËüÅÆÈİÒ×¶ÏÁËºúÂ·¡­¡­
		//tell_object(present("wiman"), "¸ÜÅÆ ");	
		if( !userp(ob) ) {
			str = who["3Ps"];
			if( do_check_Mj(str, LastDump)==3 && do_check_num(LastDump, 1)>27 && strlen(who["Mj"])<26){
				//²»Á¢Ö±¾Í¸Ü
				//PAUSE = 1;
				if( do_gon( LastDump, ob ) ) return 1;
			}			
		}		
	}
	
	//³ÔÅÆ
	who = next_data(me->query("id"), 0, "data"); 
	//str = "";
	
       	if(!userp(me) /*&& str!="" */ && who["Hu_type"]!="ponpon" ){
       		if( who["Hu_type"]!="samecolor"||who["Hu_type"]!="twocolor" ) str = who["2Es1"];
		else str = who["H2Es1"];
		i = sizeof(str);		
		//tell_object(present("wiman"), me->query("name")+"³ÔÅÆ1 ");
		if( do_check_Mj(str, next_mj(LastDump, 1))>0&&do_check_Mj(str, next_mj(LastDump, 2))>0 )  //|| 
			if( do_eat( next_mj(LastDump, 1)+" "+next_mj(LastDump, 2), me) ) return 1;
		if(do_check_Mj(str, next_mj(LastDump, -2))>0&&do_check_Mj(str, next_mj(LastDump, -1))>0 )
			if( do_eat( next_mj(LastDump, -1)+" "+next_mj(LastDump, -2), me) ) return 1;
		/*while(i>0) {
			i-=4;
			sscanf(str[i..i+1],"%d%s",num1,str1);			
			sscanf( LastDump, "%d%s", num3, str3);
			if( str1 == str3){				
				if( num3 == num1-1 || num3==num1+2){					
					do_eat( str[i..i+1]+" "+str[i+2..i+3], me );
					return 1;
				}
			}
		}*/
		//tell_object(present("wiman"), "³ÔÅÆ2 ");
		if( who["Hu_type"]!="samecolor"||who["Hu_type"]!="twocolor" ) str = who["2Es2"];
		else str = who["H2Es2"];
		//tell_object(present("wiman"), str+" ");
		if( do_check_Mj(str, next_mj(LastDump, 1))>0&&do_check_Mj(str, next_mj(LastDump, -1))>0 ) //|| 
			if( do_eat( next_mj(LastDump, 1)+" "+next_mj(LastDump, -1), me) ) return 1;
		//i = sizeof(str); 	
		/*while(i>0) {
			i-=4;
			sscanf(str[i..i+1],"%d%s",num1,str1);			
			sscanf( LastDump, "%d%s", num3, str3);
			if( str1 == str3){				
				if( num3 == num1+1 ){					
					do_eat( str[i..i+1]+" "+str[i+2..i+3], me );
					return 1;
				}
			}
		}*/
	}
	
	
	if( userp(me) ) {
		str = next_data(me->query("id"), 0, "Mj");
		if( (do_check_Mj(str, next_mj(LastDump, 1))>0&&do_check_Mj(str, next_mj(LastDump, 2))>0) || 
			(do_check_Mj(str, next_mj(LastDump, 1))>0&&do_check_Mj(str, next_mj(LastDump, -1))>0) || 
			 	(do_check_Mj(str, next_mj(LastDump, -1))>0&&do_check_Mj(str, next_mj(LastDump, -2))>0) )
		{
			tell_object( me, "Äã¿ÉÒÔÓÃ"+HIR+"chi"+NOR+"À´³ÔÅÆ£¡£¡\n");
			tell_object(me, "ÒÔÏÂÊÇÄãµÄÅÆ£º\n" +show_mj( str, 6) );
		}
	//		return 1;
	}
	//tell_object(present("wiman"), "no action\n");
	if(!userp(me)) do_touch(0, me);
	return 1;
}

int do_continue(object me)
{
	object ob;
	mapping who;
	if(!me) me = this_player();
	who = next_data( me->query("id"), 0, "data");
	ob = present(NowPlayerId[NowPlayer]);
	//tell_object( present("wiman"), NowPlayerId[NowPlayer]+"-->µ±Ç°´òÅÆÕß¡£\n");	
	//if(!Touched) {
		if( !userp(ob)&&PAUSE!=2 ) {
			//PAUSE = 0;do_touch( 0, ob );return 1;
			PAUSE = 0;
			//if( npc_action(ob) ) return 1;
			do_touch( 0, ob );return 1;
		}
		if( who["Pause"]=="yes" ) { 
			PAUSE =0; who["Pause"] = "";
			if(!userp(ob)) do_touch( 0, ob );
			else tell_room( environment(me), me->query("id")+"¶Ô"+ob->query("id")+"ËµµÀ£º¿ìÃşÅÆÀ²£¡£¡\n");
		}
		if( me==present(NowPlayerId[NowPlayer])&&PAUSE!=2 ) { 
			PAUSE =0; 
			if(!Touched) do_touch(0, me);
			else tell_room( environment(me), me->query("id")+"ËµµÀ£º±ğ¼±±ğ¼±£¡\n");
		}
		else tell_room( environment(me), me->query("id")+"¶Ô"+ob->query("id")+"ËµµÀ£º¿ìÃşÅÆÀ²£¡£¡\n");
	//}
	//else {
	//	if( !userp(ob) ) dump_what( present(ob) );
	//	else tell_room( environment(me), me->query("id")+"¶Ô"+ob->query("id")+"ËµµÀ£º¿ì³öÅÆÀ²£¡£¡\n");
	//}
	return 1;
}

//ÒÔÏÂÊÇ¶ÔÂé½«½øĞĞ½á¹¹»¯´¦ÀíµÄº¯Êı
string filt_mj(string strW, object me)
{
	int i,j,check;
	int k,t;
	int A,B,C,D,E,F;
	mapping who;
	
	who = next_data( me->query("id"), 0, "data" );
		
	if (do_check_num(strW[0..1],1) > 27){
	   for (i=0;i<strlen(strW);i+=2){//
	       check=do_check_Mj(strW,strW[i..i+1]);
	       if (check==1){
	       		who["1s"]+= strW[i..i+1];
	       		strW=do_delete_Mj(strW,strW[i..i+1],1);
	       		i=-2;
	       }
	       else if (check==2){
		       who["2Ps"]+= strW[i..i+1];
		       who["2Ps"]+= strW[i..i+1];
		       strW=do_delete_Mj(strW,strW[i..i+1],2);
		       //t++;
		       i=-2;
	       }else if (check==3){
			who["3Ps"]+= strW[i..i+1];
			who["3Ps"]+= strW[i..i+1];
			who["3Ps"]+= strW[i..i+1];
			strW=do_delete_Mj(strW,strW[i..i+1],3);
			//K++;
			i=-2;
	       }
	       else if(check == 4 ){
	       		do_gon( strW[i..i+1], me);
	       		return "";
	       }
	   }
	   return "";
	}

	for (i=0;i<sizeof(strW);i+=2) {//°ÑË³×ÓÉ¾µô
		A=do_check_num(strW[i..i+1],2);
		B=do_check_num(strW[i+2..i+3],2);
		C=do_check_num(strW[i+4..i+5],2);
		D=do_check_num(strW[i+6..i+7],2);
		E=do_check_num(strW[i+8..i+9],2);
		F=do_check_num(strW[i+10..i+11],2);       	

		if (sizeof(strW) > 11 &&do_check_num(strW[i-2..i-1],2)!=A&&A+1==B&&B==C&&C+1==D&&D==E&&E+1==F
	   	||do_check_num(strW[i-2..i-1],2)!=A&&A==B&&B+1==C&&C==D&&D+1==E&&E==F){
	   		
	      		for (j=0;j<6;j++) {  //É¾µôË³×Ó1 22 33 4 && 22 33 44
		  		strW=do_delete_Mj(strW,strW[i..i+1],1);
		  		who["3Es"] += strW[i..i+1];
	      		}
	   	i=-2;
		}
		else if (A+1==B&&B==C&&C==D&&D==E&&E+1==F){
	      		for (j=0;j<2;j++) {  //É¾µôË³×Ó1 2 2 2 2 3
	      		who["3Es"] += strW[i..i+1];
		  	strW=do_delete_Mj(strW,strW[i..i+1],1);
	      		}
	      		who["3Es"] += strW[i+6..i+7];
	      		strW=do_delete_Mj(strW,strW[i+6..i+7],1);
	   		i=-2;
	   	}
		else if (sizeof(strW) > 9 && A+1==B&&B==C&&C==D&&D+1==E){
	      				//É¾µôË³×Ó12223ÖĞµÄ1 2 3
		  	who["3Es"] += strW[i..i+1];
		  	who["3Es"] += strW[i..i+1];
		  	who["3Es"] += strW[i+4..i+5];
		  	strW=do_delete_Mj(strW,strW[i..i+1],1);
		  	strW=do_delete_Mj(strW,strW[i..i+1],1);
		  	strW=do_delete_Mj(strW,strW[i+4..i+5],1);
	   		i=-2;
		}
		else if (sizeof(strW) > 9 && A==B&&B+1==C&&C+1==D&&D+1==E){
	     		for (j=0;j<3;j++) {   //É¾µôË³×Ó11234ÖĞµÄ2 3 4
	     			who["3Es"] += strW[i+4..i+5];
		 		strW=do_delete_Mj(strW,strW[i+4..i+5],1);
	     		}
	   		i=-2;
		}
		else if (sizeof(strW) > 5 && A+1==B&&B+1==C){
	     		for (j=0;j<3;j++) {   //É¾µôË³×Ó123ÖĞµÄ1 2 3
		 		who["3Es"] += strW[i..i+1];
		 		strW=do_delete_Mj(strW,strW[i..i+1],1);
	     		}
	   		i=-2;
		}		
	}	
	if (sizeof(strW) > 5){
		for (i=0;i<sizeof(strW);i+=2) {//ÔÙ°Ñ¿ÌÉ¾µô
			check=do_check_Mj(strW,strW[i..i+1]);
			if (check==3){
				//K++;
				who["3Ps"] += strW[i..i+1];
				who["3Ps"] += strW[i..i+1];
				who["3Ps"] += strW[i..i+1];
				strW=do_delete_Mj(strW,strW[i..i+1],3);				
				i=-2;
			}
		}
	}
	for (i=0;i<sizeof(strW);i+=2) {//ÔÙ°Ñ¶ÔÉ¾µô
		check=do_check_Mj(strW,strW[i..i+1]);
		if (check==2){
			t++;
			who["2Ps"] += strW[i..i+1];
			who["2Ps"] += strW[i..i+1];
			strW=do_delete_Mj(strW,strW[i..i+1],2);
			i=-2;
		}
	}
	for (i=0;i<sizeof(strW);i+=2) {//ÔÙ°Ñ2¸öÁ¬ĞøË³×ÓÉ¾µô
		A=do_check_num(strW[i..i+1],2);
		B=do_check_num(strW[i+2..i+3],2);
		if( A==B-1 ){
			if( do_check_Mj(destop+who["Mj"], next_mj(strW[i..i+1], -1) )!=4 || 
				do_check_Mj(destop+who["Mj"], next_mj(strW[i+2..i+3], 1) )!=4 ) {
				who["2Es1"]+=strW[i..i+1];			
				who["2Es1"]+=strW[i+2..i+3];
			} else {				//Èç¹ûÁ½±ßµÄ¶¼ÒÑ¾­³öÍêÁË
				who["1s"]+=strW[i..i+1];	//ËüÒ²¾Í±ä³ÉÉ¢ÅÆ¿©
				who["1s"]+=strW[i+2..i+3];
			}			
			strW=do_delete_Mj(strW, strW[i..i+1], 1);
			strW=do_delete_Mj(strW, strW[i..i+1], 1);			
			i=-2;
		}
	}
	for (i=0;i<sizeof(strW);i+=2) {//ÔÙ°Ñ2¸ö¼ä¸ôË³×ÓÉ¾µô
		A=do_check_num(strW[i..i+1],2);
		B=do_check_num(strW[i+2..i+3],2);
		if( A==B-2 ){
			if( do_check_Mj(destop+who["Mj"], next_mj(strW[i..i+1], 1) )!=4 ) {//Èç¹ûÖĞ¼äµÄÒÑ¾­³öÍêÁË
				who["2Es2"]+=strW[i..i+1];			//ËüÒ²¾Í±ä³ÉÉ¢ÅÆ¿©
				who["2Es2"]+=strW[i+2..i+3];
			} else {
				who["1s"]+=strW[i..i+1];
				who["1s"]+=strW[i+2..i+3];
			}
			strW=do_delete_Mj(strW, strW[i..i+1], 1);
			strW=do_delete_Mj(strW, strW[i..i+1], 1);
			i=-2;
		}
	}
	who["1s"] += strW;

	   //tell_object( present("wiman"), who["1s"]+" "+who["2Ps"]+" "+who["2Es1"]+" "+"filtÍê±Ï\n");
	   
	   if (strW!="") return strW;
	   return "";
}

int filt_hu_color(string strW, object me)
{
	int i,j,check;
	int k,t;
	int A,B,C,D,E,F;
	mapping who;
	
	who = next_data( me->query("id"), 0, "data" );
		
	if (do_check_num(strW[0..1],1) > 27){
	   for (i=0;i<strlen(strW);i+=2){//
	       check=do_check_Mj(strW,strW[i..i+1]);
	       if (check==1){
	       		who["H1s"]+= strW[i..i+1];
	       		strW=do_delete_Mj(strW,strW[i..i+1],1);
	       		i=-2;
	       }
	       else if (check==2){
		       who["H2Ps"]+= strW[i..i+1];
		       who["H2Ps"]+= strW[i..i+1];
		       strW=do_delete_Mj(strW,strW[i..i+1],2);
		       //t++;
		       i=-2;
	       }else if (check==3){
			//who["3Ps"]+= strW[i..i+1];
			//who["3Ps"]+= strW[i..i+1];
			//who["3Ps"]+= strW[i..i+1];
			strW=do_delete_Mj(strW,strW[i..i+1],3);
			//K++;
			i=-2;
	       }
	       else if(check == 4 ){
	       		do_gon( strW[i..i+1], me);
	       		return 1;
	       }
	   }
	   return 1;
	}

	for (i=0;i<sizeof(strW);i+=2) {//°ÑË³×ÓÉ¾µô
		A=do_check_num(strW[i..i+1],2);
		B=do_check_num(strW[i+2..i+3],2);
		C=do_check_num(strW[i+4..i+5],2);
		D=do_check_num(strW[i+6..i+7],2);
		E=do_check_num(strW[i+8..i+9],2);
		F=do_check_num(strW[i+10..i+11],2);       	

		if (sizeof(strW) > 11 &&do_check_num(strW[i-2..i-1],2)!=A&&A+1==B&&B==C&&C+1==D&&D==E&&E+1==F
	   	||do_check_num(strW[i-2..i-1],2)!=A&&A==B&&B+1==C&&C==D&&D+1==E&&E==F){
	   		
	      		for (j=0;j<6;j++) {  //É¾µôË³×Ó1 22 33 4 && 22 33 44
		  		strW=do_delete_Mj(strW,strW[i..i+1],1);
		  		//who["3Es"] += strW[i..i+1];
	      		}
	   	i=-2;
		}
		else if (A+1==B&&B==C&&C==D&&D==E&&E+1==F){
	      		for (j=0;j<2;j++) {  //É¾µôË³×Ó1 2 2 2 2 3
	      		//who["3Es"] += strW[i..i+1];
		  	strW=do_delete_Mj(strW,strW[i..i+1],1);
	      		}
	      		//who["3Es"] += strW[i+6..i+7];
	      		strW=do_delete_Mj(strW,strW[i+6..i+7],1);
	   		i=-2;
	   	}
		else if (sizeof(strW) > 9 && A+1==B&&B==C&&C==D&&D+1==E){
	      				//É¾µôË³×Ó12223ÖĞµÄ1 2 3
		  	//who["3Es"] += strW[i..i+1];
		  	//who["3Es"] += strW[i..i+1];
		  	//who["3Es"] += strW[i+4..i+5];
		  	strW=do_delete_Mj(strW,strW[i..i+1],1);
		  	strW=do_delete_Mj(strW,strW[i..i+1],1);
		  	strW=do_delete_Mj(strW,strW[i+4..i+5],1);
	   		i=-2;
		}
		else if (sizeof(strW) > 9 && A==B&&B+1==C&&C+1==D&&D+1==E){
	     		for (j=0;j<3;j++) {   //É¾µôË³×Ó11234ÖĞµÄ2 3 4
	     			//who["3Es"] += strW[i+4..i+5];
		 		strW=do_delete_Mj(strW,strW[i+4..i+5],1);
	     		}
	   		i=-2;
		}
		else if (sizeof(strW) > 5 && A+1==B&&B+1==C){
	     		for (j=0;j<3;j++) {   //É¾µôË³×Ó123ÖĞµÄ1 2 3
		 		//who["3Es"] += strW[i..i+1];
		 		strW=do_delete_Mj(strW,strW[i..i+1],1);
	     		}
	   		i=-2;
		}		
	}	
	if (sizeof(strW) > 5){
		for (i=0;i<sizeof(strW);i+=2) {//ÔÙ°Ñ¿ÌÉ¾µô
			check=do_check_Mj(strW,strW[i..i+1]);
			if (check==3){
				//K++;
				//who["3Ps"] += strW[i..i+1];
				//who["3Ps"] += strW[i..i+1];
				//who["3Ps"] += strW[i..i+1];
				strW=do_delete_Mj(strW,strW[i..i+1],3);				
				i=-2;
			}
		}
	}
	for (i=0;i<sizeof(strW);i+=2) {//ÔÙ°Ñ¶ÔÉ¾µô
		check=do_check_Mj(strW,strW[i..i+1]);
		if (check==2){
			t++;
			who["H2Ps"] += strW[i..i+1];
			who["H2Ps"] += strW[i..i+1];
			strW=do_delete_Mj(strW,strW[i..i+1],2);
			i=-2;
		}
	}
	for (i=0;i<sizeof(strW);i+=2) {//ÔÙ°Ñ2¸öÁ¬ĞøË³×ÓÉ¾µô
		A=do_check_num(strW[i..i+1],2);
		B=do_check_num(strW[i+2..i+3],2);
		if( A==B-1 ){
			if( do_check_Mj(destop+who["Mj"], next_mj(strW[i..i+1], -1) )!=4 || 
				do_check_Mj(destop+who["Mj"], next_mj(strW[i+2..i+3], 1) )!=4 ) {
				who["H2Es1"]+=strW[i..i+1];			
				who["H2Es1"]+=strW[i+2..i+3];
			} else {				//Èç¹ûÁ½±ßµÄ¶¼ÒÑ¾­³öÍêÁË
				who["H1s"]+=strW[i..i+1];	//ËüÒ²¾Í±ä³ÉÉ¢ÅÆ¿©
				who["H1s"]+=strW[i+2..i+3];
			}			
			strW=do_delete_Mj(strW, strW[i..i+1], 1);
			strW=do_delete_Mj(strW, strW[i..i+1], 1);			
			i=-2;
		}
	}
	for (i=0;i<sizeof(strW);i+=2) {//ÔÙ°Ñ2¸ö¼ä¸ôË³×ÓÉ¾µô
		A=do_check_num(strW[i..i+1],2);
		B=do_check_num(strW[i+2..i+3],2);
		if( A==B-2 ){
			if( do_check_Mj(destop+who["Mj"], next_mj(strW[i..i+1], 1) )!=4 ) {//Èç¹ûÖĞ¼äµÄÒÑ¾­³öÍêÁË
				who["H2Es2"]+=strW[i..i+1];			//ËüÒ²¾Í±ä³ÉÉ¢ÅÆ¿©
				who["H2Es2"]+=strW[i+2..i+3];
			} else {
				who["H1s"]+=strW[i..i+1];
				who["H1s"]+=strW[i+2..i+3];
			}
			strW=do_delete_Mj(strW, strW[i..i+1], 1);
			strW=do_delete_Mj(strW, strW[i..i+1], 1);
			i=-2;
		}
	}
	who["H1s"] += strW;

	   //tell_object( present("wiman"), "filtÍê±Ï\n");
	   
	   if (strW!="") return 1;
	   return 0;
}


//ÔÚ×ÀÃæºÍ×Ô¼ºµÄÅÆÀï²é³öµÃ×î¶àµÄÅÆ
string find_mj(string str, string mj)
{
	string str4="", str3="", str2="", str1="", str0="";
	int i, num, pos;
	
	for(i=0; i<sizeof(str); i+=2){
		
		num = do_check_Mj(destop ,str[i..i+1])+ do_check_Mj(mj ,str[i..i+1]);
		switch (num) {
			case 4 : str4+=str[i..i+1];break;
			case 3 : str3+=str[i..i+1];break;
			case 2 : str2+=str[i..i+1];break;
			case 1 : str1+=str[i..i+1];break;
			default : str0+=str[i..i+1];
		}
	}
	//tell_object(present("wiman"), str1+str2+str3+str4+" find_mj here?\n");
	if(str4!="") str0 = str4;
	else if(str3!="") str0 = str3;
	else if(str2!="") str0 = str2;
	else if(str1!="") str0 = str1;
	
	for(i=0; i<sizeof(str0); i+=2){			
			if(do_check_num(str0[i..i+1],1)>27){				
				pos=i;break;
			} else if(do_check_num(str0[i..i+1], 2)==1||do_check_num(str0[i..i+1],2)==9){
				pos=i;break;
			} else pos = 2*random(sizeof(str0)/2);
		}
	//tell_object(present("wiman"), " find" +" the "+str0[pos..pos+1]+"  ");
	return str0[pos..pos+1];
}

mixed next_data( string str, int i, string key )
{
	int num, j;
	mapping who;
	
	if( i<0 ) i=4+i;
	for(j=0; j<4; j++) if(NowPlayerId[j]==str) num = j;
	num+=i;
	num%=4;
	if( P1Data["Id"]==NowPlayerId[num] ) who = P1Data;
	if( P2Data["Id"]==NowPlayerId[num] ) who = P2Data;
	if( P3Data["Id"]==NowPlayerId[num] ) who = P3Data;
	if( P4Data["Id"]==NowPlayerId[num] ) who = P4Data;
	
	switch( key ) {		
		case "data" :	return who;break;			
		case "id" :	return who["Id"];break;
		case "Mj" :	return who["Mj"];break;
		case "player" :	return present(who["Id"]);break;
		case "2Ps" :	return who["2Ps"];break;
		case "2Es1" :	return who["2Es1"];break;
		case "2Es2" :	return who["2Es2"];break;
		case "allout" :	return who["Dump"]+"zz"+who["Out"]+who["OutPon"]+who["OutFlower"];
	}
	return 0;		
}

string next_mj( string mj, int i )//ÎÒÏë¼ÈÈ»ÓĞÁËnext_data£¬²»·ÁÒ²À´¸önext_mj
{
	string str;
	int num;
	
	if(sizeof(mj)>2) return "XX";	
	if( sscanf( mj, "%d%s", num, str )!=2 ) return "XX";
	num += i;
	if( num>9 || num<1 ) return "XX";
	else return sprintf( "%d%s", num, str );
}

int get_times( mapping who )
{
	int i, j = 0;
//ËãÌ¨///////////////////////////////////
	mixed MjT = ([
"@1" : ({ "×¯¼Ò", 1 }),"@2" : ({ "×ÔÃş", 1 }),"@3" : ({ "»¨ÅÆ", 1 }),"@4" : ({ "ÃÅÇå", 1 }),"@Z" : ({ "¶ÏçÛ¾Å", 1 }),
"@5" : ({ "¶«·ç", 1 }),"@6" : ({ "ÄÏ·ç", 1 }),"@7" : ({ "Î÷·ç", 1 }),"@8" : ({ "±±·ç", 1 }),
"@9" : ({ "ºìÖĞ", 1 }),"@0" : ({ "Çà·¢", 1 }),"@a" : ({ "°×°å", 1 }),"@G" : ({ "Ò»Ø§¿Ú", 1 }),
"@b" : ({ "º£µ×ÃşÔÂ", 1 }),"@c" : ({ "º£µ×ÀÌÓã", 1 }),"@d" : ({ "Æ½ºú", 2 }),"@e" : ({ "¶«·ç¶«", 2 }),
"@f" : ({ "ÄÏ·çÄÏ", 2 }),"@g" : ({ "Î÷·çÎ÷", 2 }),"@h" : ({ "±±·ç±±", 2 }),"@i" : ({ "È«ÇóÈË", 2 }),
"@j" : ({ "Èı°µ¿Ì", 2 }),"@H" : ({ "¶şØ§¿Ú", 2 }),"@k" : ({ "Èı¸Ü×Ó", 2 }),"@B" : ({ "´ºÏÄÇï¶¬", 2 }),
"@C" : ({ "Ã·À¼¾ÕÖñ", 2 }),"@l" : ({ "ÃÅÇå×ÔÃş", 3 }),"@m" : ({ "ÅöÅöºú", 4 }),"@n" : ({ "»ìÒ»É«", 4 }),
"@o" : ({ "Ğ¡ÈıÔª", 4 }),"@p" : ({ "ËÄ°µ¿Ì", 6 }),"@q" : ({ "ÇåÒ»É«", 8 }),"@r" : ({ "×ÖÒ»É«", 8 }),
"@s" : ({ "Æß¶Ô×Ó", 8 }),"@t" : ({ "´óÈıÔª", 8 }),"@u" : ({ "Îå°µ¿Ì", 8 }),"@F" : ({ "Ğ¡ËÄÏ²", 8 }),
"@D" : ({ "ÆßÇÀÒ»", 8 }),"@E" : ({ "ÂÌÒ»É«", 16 }),"@v" : ({ "´óËÄÏ²", 16 }),"@w" : ({ "Ììºú", 16 }),
"@x" : ({ "µØºú", 16 }),"@y" : ({ "ÈËºú", 16 }),"@z" : ({ "¹úÊ¿ÎŞË«", 16 }),"@A" : ({ "°ËÏÉ¹ıº£", 16 }),
"@J" : ({ "ÇåÀÏÍ·", 8 }),"@I" : ({ "»ìÀÏÍ·", 4 }),
]);//H
	   do_check_win(who["Mj"]);
	   Tc="";
	   get_tc(who);
////////////////	   
	   for (i=0;i<sizeof(Tc);i+=2){	      
	      j+=MjT[Tc[i..i+1]][1];
	   }
	   if (Count){	      
	      j+=Count*2;
	   }
	return j;
}

//ÇåÒ»É«´ò·¨
int dump_samecolor( string str_out, string str_mj, object me)//, mapping Temps )
{
			
	mapping Temps = ([ "tempW": "", "tempT": "", "tempS": "", "tempB": "" ]);
	
	int size;
	if( str_out!="" ) get_all_temps( Temps, str_out );
	if( strlen(Temps["tempT"]+Temps["tempB"]+Temps["tempS"])==0 || str_out=="" ) {     	
		size = strlen(Temps["tempW"]);
		get_all_temps( Temps, str_mj);
		if( sizeof(Temps["tempW"])>sizeof(str_mj)/2 || size>12) {		
		//tell_object( present("wiman"), "ÇåÍò´ò·¨ ");
			if (Temps["tempT"]!="") filt_mj(Temps["tempT"], me);
			if (Temps["tempS"]!="") { //tell_object( present("wiman"), "hxhxhxhxhx\n");
				filt_mj(Temps["tempS"], me); }
			if (Temps["tempB"]!="") filt_mj(Temps["tempB"], me);
			if( Temps["tempT"]==""&&Temps["tempS"]==""&&Temps["tempB"]=="")
				filt_mj(Temps["tempW"], me);
			filt_hu_color(Temps["tempW"], me);
			return 1;
		}
	}	
	if( strlen(Temps["tempW"]+Temps["tempB"]+Temps["tempS"])==0 || str_out=="") {
		size = strlen(Temps["tempT"]);
		get_all_temps( Temps, str_mj);
		if( sizeof(Temps["tempT"])>sizeof(str_mj)/2 || size>12) {		
		//tell_object( present("wiman"), "ÇåÍ²´ò·¨ ");
			if (Temps["tempW"]!="") filt_mj(Temps["tempT"], me);
			if (Temps["tempS"]!="") filt_mj(Temps["tempS"], me);
			if (Temps["tempB"]!="") filt_mj(Temps["tempB"], me);
			if( Temps["tempW"]==""&&Temps["tempS"]==""&&Temps["tempB"]=="")
				filt_mj(Temps["tempT"], me);
			filt_hu_color(Temps["tempT"], me);
			return 1;
		}
	}	
	if(strlen(Temps["tempW"]+Temps["tempB"]+Temps["tempT"])==0 || str_out=="") {
		size = strlen(Temps["tempS"]);
		get_all_temps( Temps, str_mj);
		if( sizeof(Temps["tempS"])>sizeof(str_mj)/2 || size>12) {		
		//tell_object( present("wiman"), "ÇåS´ò·¨ ");
			if (Temps["tempT"]!="") filt_mj(Temps["tempT"], me);
			if (Temps["tempW"]!="") filt_mj(Temps["tempS"], me);
			if (Temps["tempB"]!="") filt_mj(Temps["tempB"], me);
			if( Temps["tempT"]==""&&Temps["tempW"]==""&&Temps["tempB"]=="")
				 filt_mj(Temps["tempS"], me);
			filt_hu_color(Temps["tempS"], me);
			return 1;
		}
	}	
	if(strlen(Temps["tempW"]+Temps["tempT"]+Temps["tempS"])==0 || str_out=="") {
		size = strlen(Temps["tempB"]);
		get_all_temps( Temps, str_mj);
		if( sizeof(Temps["tempB"])>sizeof(str_mj)/2 || size > 12) {		
		//tell_object( present("wiman"), "Çå×Ö´ò·¨ ");
			if (Temps["tempT"]!="") filt_mj(Temps["tempT"], me);
			if (Temps["tempS"]!="") filt_mj(Temps["tempS"], me);
			if (Temps["tempW"]!="") filt_mj(Temps["tempW"], me);
			if( Temps["tempT"]==""&&Temps["tempS"]==""&&Temps["tempW"]=="")
				filt_mj(Temps["tempB"], me);
			filt_hu_color(Temps["tempB"], me);
			return 1;
		}
	}
	
	return 0;
}

//»ìÒ»É«´ò·¨
int dump_twocolor( string str_out, string str_mj, object me, mapping Temps )
{
			
	//mapping Temps = ([ "tempW": "", "tempT": "", "tempS": "", "tempB": "" ]);
	int size;	
	//tell_object( present("wiman"), str_mj +" ");
	//tell_object( present("wiman"), "& the str_out "+str_out +" ");
	get_all_temps( Temps, str_out );
	
	if( Temps["tempT"]==""&&Temps["tempS"]=="" ) {     	
		size = strlen(Temps["tempW"]+Temps["tempB"]);
		get_all_temps( Temps, str_mj);
		if( sizeof(Temps["tempW"])>sizeof(str_mj)/2 || size>16) {		
			//tell_object( present("wiman"), "»ìÍò´ò·¨ ");
			if (Temps["tempT"]!="") filt_mj(Temps["tempT"], me);
			if (Temps["tempS"]!="") filt_mj(Temps["tempS"], me);			
			if( Temps["tempT"]==""&&Temps["tempS"]=="") {
				filt_mj(Temps["tempB"], me);filt_mj(Temps["tempW"], me);
			}
			filt_hu_color(Temps["tempB"], me);filt_hu_color(Temps["tempW"], me);
			return 1;
		}
	}	
	if( Temps["tempW"]==""&&Temps["tempS"]=="" ) {
		size = strlen(Temps["tempT"]+Temps["tempB"]);
		get_all_temps( Temps, str_mj);
		if( sizeof(Temps["tempT"])>sizeof(str_mj)/2 || size>16) {		
		//tell_object( present("wiman"), "»ìÍ²´ò·¨ ");
			if (Temps["tempW"]!="") filt_mj(Temps["tempW"], me);
			if (Temps["tempS"]!="") filt_mj(Temps["tempS"], me);			
			if( Temps["tempS"]==""&&Temps["tempW"]=="") {
				filt_mj(Temps["tempB"], me);filt_mj(Temps["tempT"], me);
			}
			filt_hu_color(Temps["tempB"], me);filt_hu_color(Temps["tempT"], me);
			return 1;
		}
	}	
	if(Temps["tempW"]==""&&Temps["tempT"]=="") {
		size = strlen(Temps["tempS"]+Temps["tempB"]);
		get_all_temps( Temps, str_mj);
		if( sizeof(Temps["tempS"])>sizeof(str_mj)/2 || size>16) {		
		//tell_object( present("wiman"), "»ìS´ò·¨ ");
			if (Temps["tempT"]!="") filt_mj(Temps["tempT"], me);
			if (Temps["tempW"]!="") filt_mj(Temps["tempW"], me);			
			if( Temps["tempT"]==""&&Temps["tempW"]=="") {
				filt_mj(Temps["tempB"], me);filt_mj(Temps["tempS"], me);
			}
			filt_hu_color(Temps["tempB"], me);filt_hu_color(Temps["tempS"], me);
			return 1;
		}
	}	
	return 0;
}

int dump_pinhu( mapping who, object me, mapping Temp )
{
	string str;
	int i;
	int check=0, check0=0;	
	get_all_temps( Temp, who["Mj"] );
	//filt
	for (i=0;i<sizeof(str);i+=2)
	  		if (do_check_num(str[i..i+1],1)>27) check0++;
	str = who["Out"]+who["OutPon"]+who["OutGon"];
	for (i=0;i<sizeof(str);i+=2)
		if (do_check_num(str[i..i+1],1)>27) check=1;
	//´ÓÕâÒÔÏÂÊÇÆ½ºú
	//if(who["OutFlower"]=="" && check<5 && !check0) {
	if( !check && who["OutPon"]=="" && check0<5 ) {
		//ÏÈ°Ñ×ÖÅÆÈÓµô
		//tell_object( present("wiman"), "Æ½ºú´ò·¨ ");
		who["Hu_type"] = "pinhu";
		if( Temp["tempB"]!="" ) {
			filt_mj( Temp["tempB"], me);
			return 1;
		}
		if (Temp["tempW"]!="") filt_mj(Temp["tempW"], me);
		if (Temp["tempT"]!="") filt_mj(Temp["tempT"], me);
		if (Temp["tempS"]!="") filt_mj(Temp["tempS"], me);
		return 1;		
	}
	return 0;
}

int dump_ponpon( mapping who, object me, mapping Temp )
{
	//mapping Temp = ([ "tempW": "", "tempT": "", "tempS": "", "tempB": "" ]);
	get_all_temps( Temp, who["Mj"] );
	if( who["Out"]=="" ) {
		if (Temp["tempB"]!="") filt_mj(Temp["tempB"], me);
		if (Temp["tempW"]!="") filt_mj(Temp["tempW"], me);
		if (Temp["tempT"]!="") filt_mj(Temp["tempT"], me);
		if (Temp["tempS"]!="") filt_mj(Temp["tempS"], me);
		if(sizeof(who["OutPon"]+ who["3Ps"])>10 || sizeof(who["OutPon"]+ who["3Ps"]+ who["2Ps"])>12) {
			//tell_object( present("wiman"), "ÅöÅö´ò·¨ ");		
			who["Hu_type"] = "ponpon";//break;
			if( who["1s"]!="") return 1;
			if( who["2Es1"]!="") return 1;
			if( who["2Es2"]!="") return 1;
			if( who["3Es"]!="") return 1;//{ tell_object(present("wiman"), NO_HU+who["3Es"]+find_mj(who["3Es"], who["Mj"])+"\n");do_dump(find_mj( who["3Es"], who["Mj"]), me);return;}
		}
		else {
			//tell_object( present("wiman"), "cancleÅöÅö´ò·¨ ");
			who["3Ps"] ="";
			who["3Es"] ="";
			who["2Ps"] ="";
			who["2Es1"] ="";
			who["2Es2"] ="";
			who["1s"] ="";
		}	
	}
	return 0;
}
	
int get_all_temps( mapping map, string str )
{
	int size;
	size = strlen(str);
	map["tempW"]="";map["tempT"]="";map["tempS"]="";map["tempB"]="";
	for(; size>=0; size-=2){
	      //size--;
	  if (do_check_num(str[size..size+1],1) < 10) map["tempW"]+=str[size..size+1];
	  else if (do_check_num(str[size..size+1],1) < 19) map["tempT"]+=str[size..size+1];
	  else if (do_check_num(str[size..size+1],1) < 28) map["tempS"]+=str[size..size+1];
	  else if( do_check_num(str[size..size+1],1) < 35) map["tempB"]+=str[size..size+1];
	}
}

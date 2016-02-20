// Feb. 6, 1999 by Winder
inherit NPC;
string inquiry_afeng();
void create()
{
	set_name("阿土", ({ "a tu","a","tu"}) );
	set("gender", "男性" );
	set("age", 18);
	set("long", "这是一个英俊潇洒的仆人。\n");
	set("shen_type", 1);
	set("combat_exp", 500);
	set("str", 16);
	set("dex", 17);
	set("con", 17);
	set("int", 18);
	set("attitude", "friendly");
	set("chat_chance",1);
	set("chat_msg",({
	    "阿土一边扫地一边摇着头。\n",
	    "阿土自言自语地说：我一直喜欢阿凤，但是怎么向她表白呢？\n",
	    "阿土突然拍了拍脑袋：对了，我给她写情书吧！\n"
	}) );
	set("inquiry",([
		"阿凤" : (: inquiry_afeng :),
	]) );
	set_temp("qingshu",1);
	setup();
	carry_object("/clone/misc/cloth")->wear();
}
string inquiry_afeng()
{
 object me=this_player();
 object obn;
 message_vision("阿土说道：这位"+ RANK_D->query_respect(me)+"，我看你也是性情中人,我就不和你绕圈子了，你能把这封信交给阿凤吗？\n", me );
 if(query_temp("qingshu")==0)
 {  message_vision("阿土又说道：这位"+ RANK_D->query_respect(me)+"，我已经托人帮我带了，也不知道她的心意如何，唉.....\n",me);
   return "";
 }
   message_vision("阿土又说道：这位"+ RANK_D->query_respect(me)+"，我这里有封我写了三天三夜的情书，麻烦你了,我后半生的幸福就托给你了。\n" , me);
   obn=new("/d/shiliang/npc/obj/qingshu");
   obn->move(me);
   set_temp("qingshu",0);
   return "请你一定交到她的手上。说完从怀里摸出一封折叠成千纸鹤般的信，交给你。\n";
}

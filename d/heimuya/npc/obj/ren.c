// renying.c

inherit NPC;
string inquiry_linghuchong();

void create()
{
	set_name("任盈盈", ({ "ren ying ying","ren","ying"}) );
	set("gender", "女性" );
	set("age", 20);
	set("long", "她身材丰腴，体态优雅，虽看上去不好接近，但无论怎样都不失为一可人的妙人。\n");
	set("shen_type", 1);
	set("combat_exp", 500000);
	set("str", 16);
	set("dex", 27);
	set("con", 17);
	set("int", 18);
	set("attitude", "friendly");
	set("chat_chance",60);
    	set("chat_msg",({
	    "不知令狐冲他，怎恙了,是否又和那小贱人在一起......\n",
        "你若能把这封信稍给他，可太谢谢你了.............\n",
        "也不知蓝凤凰见没见到他，可真急死我了.......\n",
	   }) );
       set("inquiry",([
	   "令狐冲" : (: inquiry_linghuchong :),
	   ]) );
       set_temp("letter",1);
       setup();
       carry_object("/d/heimuya/npc/obj/cloth")->wear();
       carry_object("/d/heimuya/npc/obj/letter");
}

string inquiry_linghuchong()
{
 object me=this_player();
 object obn;

 message_vision("去年上华山一去就再无音信,他不会忘记我吧......\n"
	 , me );
 if(query_temp("letter")==0)
 {  message_vision("任盈盈又说道：这位"+ RANK_D->query_respect(me)+"，我已经派
       蓝凤凰去寻找了，也不知道怎么样了。\n",me);
   return "";
 }
   message_vision("任盈盈又说道：这位"+ RANK_D->query_respect(me)+"，我这里有
       信, 你要是找到『阿冲』，就把信交给她，她会明白的。\n" , me);
   obn=new("/d/heimuya/npc/obj/letter");
   obn->move(me);
   set_temp("letter",0);
   return "任盈盈从丝袍里拿出一封信交给你。\n";
}

// Feb. 6, 1999 by Winder
inherit NPC;
string inquiry_shoupa();
void create()
{
	set_name("温仪", ({ "wen yi","wen","yi"}) );
	set("gender", "女性" );
        set("title", "温家小姐");
	set("age", 18);
	set("long", "这是一个美如天仙的女子，眉宇间却是仿佛隐藏着深忧。\n");
	set("shen_type", 1);
	set("combat_exp", 500);
	set("str", 16);
	set("dex", 17);
	set("con", 17);
	set("int", 18);
	set("attitude", "friendly");
	set("chat_chance",1);
	set("chat_msg",({
	    "温仪静静地坐着,双眼无神地望着窗外。\n",
	    "温仪自言自语地说：郎君啊，你为什么要误会我啊？——\n",
	    "温仪黯然泪下，无语地望着手中的手帕。\n",
            "突然间，温仪的脸色变得苍白起来：那...那..那碗莲子羹......\n"
	   }) );
       set("inquiry",([
	   "手帕" : (: inquiry_shoupa :),
           "金蛇郎君" : "他是我心目中英雄的郎君....",
	   ]) );
       set_temp("shoupa",1);
       setup();
        carry_object("/d/city/obj/necklace")->wear();
        carry_object("/d/city/obj/pink_cloth")->wear();
        carry_object("/d/city/obj/flower_shoe")->wear();
        carry_object("/d/city/obj/goldring")->wear();
}
string inquiry_shoupa()
{
 object me=this_player();
 object obn;
 message_vision("温仪说道：这位"+ RANK_D->query_respect(me)+"，你能帮我个忙吗？我只是想让郎君知道我的心意。\n", me );
 if(query_temp("shoupa")==0)
 {  message_vision("温仪又说道：这位"+ RANK_D->query_respect(me)+"，我已经托人帮我带了，就不麻烦你了。\n",me);
   return "";
 }
   message_vision("温仪说道：这位"+ RANK_D->query_respect(me)+"，这是我和郎君的信物，看见它，他就知道我的心意了。\n" , me);
   obn=new("/d/shiliang/npc/obj/shoupa");
   obn->move(me);
   set_temp("shoupa",0);
   return "请你一定交到他的手上，他就在庄西的山洞中。说完，温仪给你一张绣花的手帕。\n";
}

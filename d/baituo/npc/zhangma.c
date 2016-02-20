// zhangma.c
// Last Modified by Winder on May. 15 2001

inherit NPC;
string inquiry_hua();

void create()
{
	set_name("张妈", ({ "zhang ma","zhang","ma"}) );
	set("gender", "女性" );
	set("age", 50);
	set("long", "一个历经沧桑的老婆婆。\n");
	set("shen_type", 1);
	set("combat_exp", 500);
	set("str", 16);
	set("dex", 17);
	set("con", 17);
	set("int", 18);
	set("attitude", "friendly");
	set("chat_chance",60);
	set("chat_msg",({
		"张妈念叨着：我苦命的『金花』哟，你现在在那里哟￣\n",
		"张妈暗暗抹了把眼泪。\n",
		"张妈独自说道：我的『金花』呀，你怎能撇下我自个儿走了￣\n"
	}) );
	set("inquiry",([
		"金花" : (: inquiry_hua :),
	]) );
	set_temp("shoe",1);
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

string inquiry_hua()
{
	object me=this_player();
	object obn;
	message_vision("张妈说道：这位"+ RANK_D->query_respect(me)+"，『金花』是我的亲闺女，\n甭提多孝顺了！\n可惜去年上山割草就一去不会，也不知是死是活。唉！\n", me );
	if(query_temp("shoe")==0)
	{
		message_vision("张妈又说道：这位"+ RANK_D->query_respect(me)+"，我已经托\n人去寻找了，也不知道怎么样了。\n",me);
		return "";
	}
	message_vision("张妈又说道：这位"+ RANK_D->query_respect(me)+"，我这里有她落在草丛里的一只「绣花鞋」，\n你要是找到『金花』，就把鞋交给她，她会明白的。\n我女儿『金花』的命运，就托给你了。\n" , me);
	obn=new("/d/baituo/obj/shoe");
	obn->move(me);
	set_temp("shoe",0);
	return "张妈从怀里摸出一只「绣花鞋」，交给你。\n";
}

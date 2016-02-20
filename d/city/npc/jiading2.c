// jiading.c 家丁

inherit NPC;
string ask_kid();

void create()
{
	set_name("家丁", ({ "jia ding", "jia" }));
	set("gender", "男性");
	set("age", 35);

	set("combat_exp", 4000);
	set_skill("dodge", 20);
	set_skill("unarmed", 20);
	set_temp("apply/attack",  10);
	set_temp("apply/defense", 10);
	set("shen_type", -1);

	set("chat_chance", 30);
	set("chat_msg", ({
		"家丁道：去去，一边去。。。\n",
        "嗯。家丁皱了皱眉头，一副不爱理人的样子。\n",
        "家丁道：你能不能别来烦我？\n"
    }) );
    
	set( "inquiry", ([
		"杨府" : "哈哈，你不正在杨府门口吗？\n",
		"小玲珑山馆" : "就是杨府。\n",
		"扬州" : "扬州繁华甲天下！\n",
		"杨磊石" : (: ask_kid :)
	]) );
	setup();
	add_money("silver",3);
	carry_object("/clone/misc/cloth")->wear();
}

string ask_kid()
{
    if ( this_player()->query_temp( "kid_ask" ) )
    {
    }
    else
        return "那是我家少爷。\n";
}

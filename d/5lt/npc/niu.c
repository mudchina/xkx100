// niu.c

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("牛", ({ "niu" }));
	set("title", "隐士");
	set("shen_type", 1);

	set("gender", "男性" );
	set("long", @LONG
他就是电视台的农业副业主编，年少时投身明教，追随张教主行走
江湖多年，立下了赫赫战功，急流勇退后隐于无厘头村。
LONG);
	set("nickname", HIG"农业频道主任·林业副业频道主编"NOR);
	set("age", 30);
	set("per", 30);
	set("attitude", "friendly");		
        set("no_get", "1");
	set("env/no_teach", "1");

	set("inquiry", ([
                 "yoyo": "你问台长啊，他在电视台，你是要做广告吗？\n",
           "singleblue": "细胳膊啊，她是我的无敌搭档啊。\n",
                  "lip": "那个可怜的猪头，正在大连泡mm呢。",
               "fandog": "恩，大狗狗是我们最敬仰的村长。",
                  "niu": "问什么问，没见过长得帅的牛吗？",
	]));   
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 1400);
	set("max_jing", 700);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 150);

	set("combat_exp", 3000000);
	set_skill("force", 250);
	set_skill("jiuyang-shengong", 250);
	set_skill("dodge", 250);
	set_skill("qiankun-danuoyi", 250);
	set_skill("cuff", 250);
	set_skill("qishang-quan", 250);
	set_skill("parry", 250);
	set_skill("sword", 250);
	set_skill("shenghuo-ling", 250);
	set_skill("taoism", 150);
	set_skill("literate", 300);

	map_skill("force", "jiuyang-shengong");
	map_skill("dodge", "qiankun-danuoyi");
	map_skill("cuff", "qishang-quan");
	map_skill("parry", "qishang-quan");
	map_skill("sword", "shenghuo-ling");
	setup();

	carry_object(CLOTH_DIR"niupi-dayi")->wear();
        carry_object(CLOTH_DIR"niupi-xue")->wear();
}
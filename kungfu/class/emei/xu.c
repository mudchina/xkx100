// xu.c ����ʦ̫
// Modified by That Oct.1997
#include <command.h>
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string ask_for_join();
int peiyao();
int liandan();
void create()
{
	set_name("����ʦ̫", ({ "jingxu shitai","jingxu","shitai"}));
	set("long", "���Ƕ����ɶ�ʦ�㣬�������¶��꣬һ�׶����Ʒ�������������˵
����ҩ�������������������衣\n");
	set("gender", "Ů��");
	set("age", 43);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("shen", 10000);
	set("class", "bonze");
	set("inquiry",([
		"���"  : (: ask_for_join :),
		"����"  : (: ask_for_join :),
		"��ҩ"  : ( : peiyao :),
		"������": ( : liandan : ),
		"����"  : "���ҵ��ӣ����ܻ��ס���������ʦ̫�ɡ�",
	]));

	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 20);

	set("max_qi", 1000);
	set("max_jing", 500);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jingli", 1500);
	set("max_jingli", 1500);

	set("combat_exp", 250000);
	set("score", 1000);
	set_skill("persuading", 80);
	set_skill("throwing", 80);
	set_skill("force", 100);
	set_skill("dodge", 90);
	set_skill("finger", 100);
	set_skill("parry", 90);
	set_skill("strike", 80);
	set_skill("blade", 100);
	set_skill("literate", 90);
	set_skill("mahayana", 100);
	set_skill("jinding-zhang", 120);
	set_skill("tiangang-zhi", 150);
	set_skill("yanxing-dao", 150);
	set_skill("zhutian-bu", 150);
	set_skill("linji-zhuang", 100);
	map_skill("force","linji-zhuang");
	map_skill("finger","tiangang-zhi");
	map_skill("dodge","zhutian-bu");
	map_skill("strike","jinding-zhang");
	map_skill("blade","yanxing-dao");
	map_skill("parry","yanxing-dao");
	prepare_skill("strike", "jinding-zhang");
	prepare_skill("finger", "tiangang-zhi");
	set("env/wimpy", 60);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
//		(: perform_action, "sword.mie" :),
		(: perform_action, "blade.wuxing" :),
		(: perform_action, "strike.bashi" :),
		(: perform_action, "finger.lingkong" :),		
		(: exert_function, "powerup" :),				
		(: exert_function, "recover" :),
		(: exert_function, "regenerate" :),
	}) );

	create_family("������", 4, "����");

	setup();
	carry_object(WEAPON_DIR"gangdao")->wield();
	carry_object(CLOTH_DIR"ni-cloth")->wear();
	carry_object(CLOTH_DIR"ni-shoe")->wear();
}
void init()
{
	add_action("do_kneel", "kneel");
}
void attempt_apprentice(object ob)
{
	if( (string)ob->query("class")!="bonze" )
	{
		command ("say �����ӷ�ƶ�᲻�յ��ӡ�\n");
		command ("say ���������ѧ�����ɵĹ��򣬻���ȥ�����׼�ʦ�ðɡ�\n");
		return;
	}

	if( (string)ob->query("gender") != "Ů��" )
	{
		command ("say �����ӷ�ƶ�᲻���е��ӡ�ʩ������ѧ�տ�ȥ�����׼�ʦ�á�");
		return;
	}
	if ((int)ob->query("shen") < 100)
	{
		command("say " + RANK_D->query_respect(ob) + "����������֮�»����Ĳ�����");
		return;
	}
	if ((int)ob->query_skill("mahayana",1) <50)
	{
		command("say ���˷𷨵���Ϊ��Ҫ���Щ��");
		return;
	}
	command("say �����ӷ����գ����գ��ðɣ��Ҿ��������ˡ�");
	command("say ϣ�������Դȱ�֮�ģ����ǻ�֮����Ŭ�����ƣ��ö�������");
	command("recruit " + ob->query("id"));
}

int peiyao()
{
	object me = this_player();
	object ob = this_object();
	object obj;
	int i;

	if(!objectp(present("caoyao 3",me)))
	{
		command("say �������û����ô���ҩ��");
		return 1;
	}
	for(i=0;i<3;i++)
	{
		obj=present("caoyao",me);
		destruct(obj);
	}
	command("smile");
	command("say �ðɣ��Ҿ͸�����ҩ�ˡ�");
	obj=new("/d/emei/obj/zhongyao");
	obj->move(me);
	message_vision("����ʦ̫��$Nһ����ҩ��\n",me);
	return 1;
}
int liandan()
{
	object me = this_player();
	object ob = this_object();
	object obj;
	int i;
	if(!objectp(present("liuhuang",me)))
	{
		command("say �������û�������������õ���ǡ�");
		return 1;
	}
	obj=present("liuhuang",me);
	destruct(obj);
	command("smile");
	command("say �ðɣ��Ҿ͸�������һ����������");
	obj=new("/d/emei/obj/pilidan");
	obj->move(me);
	message_vision("����ʦ̫��$Nһ����������\n",me);
	return 1;
}
#include "emei.h"
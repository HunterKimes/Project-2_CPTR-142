# This file contains unittests to confirm that all funtions work properly

import functions
import unittest

debug = False

class TestParagraph(unittest.TestCase):
    def test_complexWord(self):
        self.assertEqual(functions.complexWords("no aeiou.", debug), 1)

    def test_countSentences(self):
        self.assertEqual(functions.countSentences("Hi mom. How are you?", debug), 2)

    def test_countWords(self):
        self.assertEqual(functions.countWords("Hi mom. hi mom.", debug), 4)

    def test_spaceTest(self):
        self.assertEqual(functions.spaceTest("Hi  mom", debug), 0)

    def test_periodTest(self):
        self.assertEqual(functions.periodTest("Hi mom..", debug), 0)

    def test_countCharacters(self):
        self.assertEqual(functions.countCharacters("Hi mom.", debug), 5)

temp = TestParagraph()
temp.test_complexWord()
temp.test_countSentences()
temp.test_countWords()
temp.test_spaceTest()
temp.test_periodTest()
temp.test_countCharacters()

